#include<stdio.h>

int findMaxLength(int* nums,int size);
void calCount1(const int* nums,int* count1,int size);
void calCount0(const int* nums,int* count0,int size);

int main()
{
	int nums[] = {0,0,1,0,1,0,1,1,1,1,0,0,0,0,1,0,0,0,1,1};
	printf("MaxLength:%d",findMaxLength(nums,20));
}

/*	  nums: [1,0,1,0,1,1,1,1,0,0,0,0,1]
0~i有幾個1:	[1 1 2 2 3 4 5 6 6 6 6 6 7]
1~i有幾個1:	[- 0 1 1 2 3 4 5 5 5 5 5 6]
4~i有幾個1:	[- - - - 1 2 3 4 4 4 4 4 5]
i~j有幾個1: count1[j]-count1[i-1]	i,j為陣列index,注意值範圍是否正常

0~i有幾個0:	[0 1 1 2 2 2 2 2 3 4 5 6 6]
同上
*/
int findMaxLength(int* nums,int size)
{
	int count0[size];
	int count1[size];
	calCount0(nums,count0,size);
	calCount1(nums,count1,size);
	
	int maxLength = 0;
	int length = 0;

	for(int i=0;i < size;i++)
	{
		for(int j=i+1;j < size;j++)
		{
			if(i == 0 && count1[j] == count0[j])	//i == 0 時,count[i-1] => count[-1]未定義
				length = j + 1;	
			else if(count1[j]-count1[i-1] == count0[j]-count0[i-1])	//i~j 0的個數 == 1的個數
			//前後交換一下 count1[j]-count0[j] == count1[i-1]-count0[i-1]
			//0~j 1和0的差值 == 0~(i-1) 1和0的差值
				length = j - i + 1;
			if(length > maxLength)
				maxLength = length;
			printf("i = %d , j = %d , length = %d , MaxLength = %d\n",i,j,length,maxLength);
		}
	}
	return maxLength;
}

void calCount1(const int* nums,int* count1,int size)
{
	for(int i=0;i < size;i++)
		if(i == 0)
		{
			if(nums[i] == 1)
				count1[0] = 1;
			else
				count1[0] = 0;
		}
		else
		{
			if(nums[i] == 1)
				count1[i] = count1[i-1] + 1;
			else
				count1[i] = count1[i-1];
		}
}

void calCount0(const int* nums,int* count0,int size)
{
	for(int i=0;i < size;i++)
		if(i == 0)
		{
			if(nums[i] == 0)
				count0[0] = 1;
			else
				count0[0] = 0;
		}
		else
		{
			if(nums[i] == 0)
				count0[i] = count0[i-1] + 1;
			else
				count0[i] = count0[i-1];
		}
}