#include<stdio.h>
#include<stdlib.h>

int stockProfit(int* stock,int size);

int main()
{
	int stock[] = {7,1,5,3,6,4};
	printf("最大利潤為：%d",stockProfit(stock,6));
}


int stockProfit(int* stock,int size)
{
	int* maxProfit = (int*)malloc(size*sizeof(int));
	maxProfit[0] = 0;
	for(int i=0;i < size;i++)
	{
		maxProfit[i] = 0;
		for(int j=0;j < i;j++)
		{
			maxProfit[i] = 0;
			if(stock[i]-stock[j] > 0)
				maxProfit[i] = maxProfit[j]+(stock[i]-stock[j]);
			else
				maxProfit[i] = maxProfit[j];
		}
	}
	int temp = maxProfit[size-1];
	free(maxProfit);
	return temp;
}