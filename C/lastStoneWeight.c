#include<stdio.h>
#include<stdlib.h>

int lastStoneWeight(int* stones,int size);
int cmp(const void* a,const void* b);

int main()
{
	int stones[] = {2,7,4,1,8,1};
	printf("lastStoneWeight is:%d\n",lastStoneWeight(stones,6));	
}

int lastStoneWeight(int* stones,int size)
{
	qsort(stones,size,sizeof(int),cmp);	//�˱ԱƦC
	
	while(size > 1)
	{
		if(stones[0] == stones[1])
		{
			stones[0] = stones[1] = 0;
			qsort(stones,size,sizeof(int),cmp);
			size -= 2;
		}
		else
		{
			stones[0] -= stones[1];
			stones[1] = 0;
			qsort(stones,size,sizeof(int),cmp);
			size--;
		}
	}
	return stones[0];
}

int cmp(const void* a,const void* b)
{
	return *(const int*)b - *(const int*)a;
}