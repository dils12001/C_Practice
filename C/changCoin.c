#include<stdio.h>

int minNum(int a,int b);
int coinChange(int* kindsOfCoin,int size,int changeNum);

int main()
{
	int kindsOfCoin[] = {2,5,7};
	int changeNum;
	printf("�n�N�h�֤��I�����w���A�w��������{2,5,7}: ");
	scanf("%d",&changeNum);
	int a = coinChange(kindsOfCoin,3,changeNum);
	if(a >= 0)
		printf("�I�� %d ���A�ֻ̤ݭn %d �T�w��",changeNum,a);
	else
		printf("���i��εw���I�� %d ��");
}
/*
��X�̫�@�B�ä��R�W�ߡG
	����27�����̫�@�B,Ak = 2 or 5 or 7�A�ֶ̤���k�B
	����27�����˼ƲĤG�B(�e�e�@�B)�A�@�ݴ���27-A(k-1)���A27-2 or 27-5 or 27-7���A�ֶ̤���k�B
	
�C�X�ಾ��{�G
	F[i] = min(F[i-2]+1,F[i-5]+1,F[i-7]+1)
	
��l����G
	F[0] = 0
	
��ɱ��ΡG
	(1)�YF[i-2]=F[-2]�������Ϊ�ܶW�X��ɡA���]�w���� i-2 >= 0 �~���ʧ@
	(2)��F[i] = F[i-2]+1	F[i-2]=���L�a(�]���D���̤p���A���L�a��ܨS����֪��w���Ưഫ�A�Y�L�k�I��)
				F[i-2]+1 = ���L�a�[1 -> ���� ���]�w���� F[i-2] != ���L�a �~���ʧ@
	�@�}�lF[i]������� = ���L�a ���ۤ@�ӭ�(F[i-2]+1,...)��j�p �p�����NF[i]

�p�ⶶ�ǡG
	�Ѥp��j(���D)or�Ѥj��p
	F[0] = 0
	�̧ǭp�� F[1],F[2],...,F[27]
*/
					//��I��������{2,5,7}	�������I���h�ֿ� 27
int coinChange(int* kindsOfCoin,int size,int changeNum)
{
	int bestChangeCount[changeNum+1];	//bestChangeCount[M]�O�I��M����"�̤p"�w����	testMyComputer->�̰�[520023+1]
	bestChangeCount[0] = 0;	//��l����A�I��0���ɡA�� 0 �ش��k
	for(int i = 1;i <= changeNum;i++)
	{	//printf("i = %d\n",i);
		bestChangeCount[i] = INT_MAX;
		for(int j = 0;j < size;j++)	//i-2 or i-5 or i-7 ��	
		{
			if( (i-kindsOfCoin[j]) >= 0 && bestChangeCount[i-kindsOfCoin[j]] != INT_MAX )	//��ɳ]�m
				bestChangeCount[i] = minNum(bestChangeCount[i-kindsOfCoin[j]]+1,bestChangeCount[i]);
		}	//printf("F(%d) = %d\n",i,bestChangeCount[i]);
	}
	if(bestChangeCount[changeNum] == INT_MAX)
		return -1;
	return bestChangeCount[changeNum];
}

int minNum(int a,int b)
{
	int min = a;
	if(b < a)
		min = b;
	return min;
}


