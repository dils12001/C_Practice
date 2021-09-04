#include<stdio.h>

int minNum(int a,int b);
int coinChange(int* kindsOfCoin,int size,int changeNum);

int main()
{
	int kindsOfCoin[] = {2,5,7};
	int changeNum;
	printf("要將多少元兌換成硬幣，硬幣種類為{2,5,7}: ");
	scanf("%d",&changeNum);
	int a = coinChange(kindsOfCoin,3,changeNum);
	if(a >= 0)
		printf("兌換 %d 元，最少需要 %d 枚硬幣",changeNum,a);
	else
		printf("不可能用硬幣兌換 %d 元");
}
/*
找出最後一步並分析規律：
	換到27元的最後一步,Ak = 2 or 5 or 7，最少須拿k步
	換到27元的倒數第二步(前前一步)，共需換到27-A(k-1)元，27-2 or 27-5 or 27-7元，最少須拿k步
	
列出轉移方程：
	F[i] = min(F[i-2]+1,F[i-5]+1,F[i-7]+1)
	
初始條件：
	F[0] = 0
	
邊界情形：
	(1)若F[i-2]=F[-2]類似情形表示超出邊界，須設定條件 i-2 >= 0 才做動作
	(2)當F[i] = F[i-2]+1	F[i-2]=正無窮(因本題找找最小的，正無窮表示沒有更少的硬幣數能換，即無法兌換)
				F[i-2]+1 = 正無窮加1 -> 溢位 須設定條件 F[i-2] != 正無窮 才做動作
	一開始F[i]都先賦值 = 正無窮 接著一個個(F[i-2]+1,...)比大小 小的取代F[i]

計算順序：
	由小到大(本題)or由大到小
	F[0] = 0
	依序計算 F[1],F[2],...,F[27]
*/
					//能兌換的幣值{2,5,7}	本次欲兌換多少錢 27
int coinChange(int* kindsOfCoin,int size,int changeNum)
{
	int bestChangeCount[changeNum+1];	//bestChangeCount[M]是兌換M元的"最小"硬幣數	testMyComputer->最高[520023+1]
	bestChangeCount[0] = 0;	//初始條件，兌換0元時，有 0 種換法
	for(int i = 1;i <= changeNum;i++)
	{	//printf("i = %d\n",i);
		bestChangeCount[i] = INT_MAX;
		for(int j = 0;j < size;j++)	//i-2 or i-5 or i-7 時	
		{
			if( (i-kindsOfCoin[j]) >= 0 && bestChangeCount[i-kindsOfCoin[j]] != INT_MAX )	//邊界設置
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


