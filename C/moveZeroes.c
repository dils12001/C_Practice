#include<stdio.h>
#include<stdlib.h>

void moveZeroes(int* nums,int size);

int main()
{
	int nums[] = {3,0,0,84,12,0,1,0};
	moveZeroes(nums,8);
	for(int i=0;i < 8;i++)
		printf("%d\t",nums[i]);
	
}

void moveZeroes(int* nums,int size)	//[3,12,0,1,0]
{
	int* temp = (int*)malloc(size*sizeof(int));
	temp = calloc(size,sizeof(int));
	for(int i = 0;i < size;i++)
		temp[i] = nums[i];
	
	int i = 0;
	int j = size-1;
	for(int k = 0;k < size;k++)
	{
		if(temp[k] == 0)
		{
			nums[j] = temp[k];
			j--;
		}
		else
		{
			nums[i] = temp[k];
			i++;
		}	
	}
	free(temp);
}