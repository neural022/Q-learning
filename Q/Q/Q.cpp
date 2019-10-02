// Q-learning.cpp: �w�q�D���x���ε{�����i�J�I�C
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

//	��e���A�A�Ҧ��i��action��@��(�è�)
int s_act(int s)
{
	return rand() % 6;
}
//	�����p��
float QQ(int s, int a)
{
	float max_a = -100;
	for (int aa = 0; aa < 6; aa++) if (Q[a][aa] > max_a) max_a = Q[a][aa];	//	��̦n���@�����|
	return R[s][a] + gamma * max_a;	//	R[s][a] s��a�����S
}
int main()
{
	//	step2:�OQ�x�}��0
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++) Q[i][j] = 0;
	srand(time(NULL)); rand();
	//	����1000��(�ǲ�)
	for (int i = 0; i < 1000; i++)
	{
		//	�H������ 0 ~ 4 ����l���A
		int s = rand() % 6;
		// ���F�ؼЪ��A5�~�����
		while (s != 5)
		{
			int a = s_act(s);
			Q[s][a] = QQ(s, a);
			s = a;
		}
	}
	//	�L�XQ�x�}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++) printf("%6.2f\t", Q[i][j]);
		printf("\n");
	}
	return 0;
}



