#include<stdio.h>
#include<stdlib.h>

int* productExceptSelf(int* nums,int size);

int main()
{
	int nums[] = {1,2,3,4,5,6};
	int* productArr = productExceptSelf(nums,6);
	for(int i=0;i < 6;i++)
		printf("[%d] ",productArr[i]);
	free(productArr);
}


int* productExceptSelf(int* nums,int size)	//限制不能用除法 time:O(N)
{
	int* returnArr = malloc(sizeof(int)*size);
	
	//不乘nums[i],所以returnArr = 
	//nums[0]*nums[1]*...*nums[i-1] 乘以 nums[i+1]*nums[i+2]*...*nums[size-1]
	
	int left[size];
	int right[size];
	
	//      [ 1 , 2 , 3 , 4 , 5 , 6 ]
	//left    1 , 1 , 2 , 6 , 24,120
	//right  720,360,120, 30, 6 , 1 

	left[0] = 1;
	for(int i=1;i < size;i++)
		left[i] = left[i-1] * nums[i-1];

	right[size-1] = 1;
	for(int i=size-2;i >= 0;i--)
		right[i] = right[i+1] * nums[i+1];

	for(int i=0;i < size;i++)
		returnArr[i] = left[i]*right[i];
	
	return returnArr;
}