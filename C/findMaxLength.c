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
0~i���X��1:	[1 1 2 2 3 4 5 6 6 6 6 6 7]
1~i���X��1:	[- 0 1 1 2 3 4 5 5 5 5 5 6]
4~i���X��1:	[- - - - 1 2 3 4 4 4 4 4 5]
i~j���X��1: count1[j]-count1[i-1]	i,j���}�Cindex,�`�N�Ƚd��O�_���`

0~i���X��0:	[0 1 1 2 2 2 2 2 3 4 5 6 6]
�P�W
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
			if(i == 0 && count1[j] == count0[j])	//i == 0 ��,count[i-1] => count[-1]���w�q
				length = j + 1;	
			else if(count1[j]-count1[i-1] == count0[j]-count0[i-1])	//i~j 0���Ӽ� == 1���Ӽ�
			//�e��洫�@�U count1[j]-count0[j] == count1[i-1]-count0[i-1]
			//0~j 1�M0���t�� == 0~(i-1) 1�M0���t��
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