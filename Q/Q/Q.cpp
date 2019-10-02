// Q-learning.cpp: 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "stdlib.h"
#include "time.h"

float R[6][6] = {
	-100, -100, -100, -100, 0, -100,
	-100, -100, -100, 0, -100, 100,
	-100, -100, -100, 0, -100, -100,
	-100, 0, 0, -100, 0, -100,
	0, -100, -100, 0, -100, 100,
	-100, 0, -100, -100, 0, 100
};

float Q[6][6];
float gamma = 0.8;

//	當前狀態，所有可能action選一個(亂走)
int s_act(int s)
{
	return rand() % 6;
}
//	公式計算
float QQ(int s, int a)
{
	float max_a = -100;
	for (int aa = 0; aa < 6; aa++) if (Q[a][aa] > max_a) max_a = Q[a][aa];	//	找最好的一條路徑
	return R[s][a] + gamma * max_a;	//	R[s][a] s到a的報酬
}
int main()
{
	//	step2:令Q矩陣為0
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++) Q[i][j] = 0;
	srand(time(NULL)); rand();
	//	模擬1000次(學習)
	for (int i = 0; i < 1000; i++)
	{
		//	隨機產生 0 ~ 4 的初始狀態
		int s = rand() % 6;
		// 未達目標狀態5繼續執行
		while (s != 5)
		{
			int a = s_act(s);
			Q[s][a] = QQ(s, a);
			s = a;
		}
	}
	//	印出Q矩陣
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++) printf("%6.2f\t", Q[i][j]);
		printf("\n");
	}
	return 0;
}



