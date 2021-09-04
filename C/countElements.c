#include<stdio.h>
#include<stdlib.h>

int cmpInt(const void* a,const void* b);
int countElements(int* nums,int size);

int main()
{
	int nums[] = {1,3,2,3,5,0,4,4};
	printf("\nOutput:%d",countElements(nums,8));
	
}

/*			[0,1,2,3,3,4,4,5]
	sameNum  1 1 1 1 2 1 2 1 
	count	 0 1 2 3 3 5 5 7 
*/
int countElements(int* nums,int size)
{
	qsort(nums,size,sizeof(int),cmpInt);
	
	int count = 0;
	int sameNum = 1;
	
	for(int i=1;i < size;i++)
	{
		if(nums[i] == nums[i-1])
			sameNum++;
		else if(nums[i] == nums[i-1]+1)
		{
			count += sameNum;
			sameNum = 1;
		}
		else
			sameNum = 1;
		printf("i = %d\tnums[i] = %d\tsameNum = %d\tcount = %d\n",i,nums[i],sameNum,count);
	}
	/*int count = 0;
	int lastRecord = 0;

	for(int i=0;i < size-1;i++)	//最後一個元素不用拿來算count,他沒有下一個元素,不可能+1
	{
		printf("i = %d\n\n",i);
		if(i != 0 && nums[i] == nums[i-1])
		{
			printf("b");
			count += lastRecord;
			printf("nums[i] = %d,count = %d\n",nums[i],count);
			continue;
		}
		for(int j=i+1;j < size;j++)
		{			
			printf("c");
			lastRecord = 0;
			if(nums[i]+1 == nums[j])
			{
				printf("d");
				count++;
				lastRecord = 1;
				break;
			}	
		}printf("nums[i] = %d,count = %d\n",nums[i],count);
	}*/
	return count;
}

int cmpInt(const void* a,const void* b)
{
	return *(const int*)a - *(const int*)b;
}

