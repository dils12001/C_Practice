#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp_char(const void* _a , const void* _b);
int cmp_strPair(const void* _a , const void* _b);
char*** groupAnagrams(char** strs,int strsSize,int* returnSize,int** returnColumnSizes);


typedef struct
{
	char* original;	//原始字串
	char* sorted;	//排序過的字串
}strPair;	//直接自訂義一個匿名struct,並設定別名為strPair,即宣告時直接使用strPair當type名

int main()
{
	//char** strs = {{"eat"},{"tea"},{"tan"},{"ate"},{"nat"},{"bat"}};
	char* strs[6] = {"eat","tea","tan","ate","nat","bat"};
	int returnSize;
	int* returnColumnSizes;
	
	char*** returnResult = groupAnagrams(strs,6,&returnSize,&returnColumnSizes);

	for(int i=0;i < returnSize;i++)
	{
		for(int j=0;j < returnColumnSizes[i];j++)
		{
			printf("%s\n",returnResult[i][j]);
		}
	}
	
}



char*** groupAnagrams(char** strs,int strsSize,int* returnSize,int** returnColumnSizes)
{
	strPair* myPairs = malloc(sizeof(strPair)*strsSize);

	for(int i=0;i < strsSize;i++)
	{
		char* sorted_temp = malloc(sizeof(char)*(strlen(strs[i])+1));//(strlen(strs[i])+1)
		strcpy(sorted_temp,strs[i]); 	//先把strs[i]複製到sorted_temp
		qsort(sorted_temp,strlen(strs[i]),sizeof(char),cmp_char);	//再把sorted_temp排序	

		myPairs[i].original = strs[i];	//myPairs[i].original指到strs[i]
		myPairs[i].sorted = sorted_temp;	//myPairs[i].sorted指到sorted_temp
	}
	
	qsort(myPairs,strsSize,sizeof(strPair),cmp_strPair);
	
	/*for(int i=0;i < strsSize;i++)
		printf("original:%s  sorted:%s\n",myPairs[i].original,myPairs[i].sorted);*/
	
	char*** returnResult = NULL;
	*returnSize = 0;	//returnResult的陣列長度[[char**],[char**],[]]本題應為3 char**為字串陣列
	*returnColumnSizes = NULL;	//為各個char**裡的元素 數目[1(bat),2(tan,nat),3(eat,ate,tea)]
	
	for(int i=0;i < strsSize;i++)
	{
		if(i == 0 || myPairs[i].sorted != myPairs[i-1].sorted)	//第一次 跟 每一次字串跟上一次不同時,新增一個群組
		{
			(*returnSize)++;	//字串群組加1
			returnResult = realloc(returnResult,sizeof(char**)*(*returnSize));	//再新增一個群組(char**字串陣列),realloc成2(1+1)
			returnResult[(*returnSize)-1] = malloc(sizeof(char*)*1);	//第?個字串群組的陣列,在裡面新增一個字串(char*)
			returnResult[(*returnSize)-1][0] =  myPairs[i].original;	//新增字串進去(第?群組的第一個元素)
	
			*returnColumnSizes = realloc(*returnColumnSizes,sizeof(int)*(*returnSize));
			//第一個群組有一個元素int (*returnColumnSizes)[1+1],(*returnColumnSizes)的元素數目等於有?個字串群組
			(*returnColumnSizes)[(*returnSize)-1] = 1;	//int (*returnColumnSizes)[2] = {1,1};
			
			/*returnResult = malloc(sizeof(char**)*1);	//新增一個群組(char**字串陣列)
			returnResult[0] = malloc(sizeof(char*)*1);	//第一個字串群組的陣列,在裡面新增一個字串(char*)
			returnResult[0][0] =  myPairs[i].original;	//新增字串進去
			*returnSize = 1;	//字串群組加1
			*returnColumnSizes = malloc(sizeof(int)*1);	//第一個群組有一個元素int (*returnColumnSizes)[1]
			(*returnColumnSizes)[0] = 1;	//int (*returnColumnSizes)[1] = {1};
			
			
			returnResult = realloc(returnResult,sizeof(char**)*2);	//再新增一個群組(char**字串陣列),realloc成2(1+1)
			returnResult[1] = malloc(sizeof(char*)*1);	//第二個字串群組的陣列,在裡面新增一個字串(char*)
			returnResult[1][0] =  myPairs[i].original;	//新增字串進去(第二群組的第一個元素)
			*returnSize = 2;	//字串群組再加1
			*returnColumnSizes = realloc(*returnColumnSizes,sizeof(int)*2);	//第一個群組有一個元素int (*returnColumnSizes)[1+1]
			(*returnColumnSizes)[1] = 1;	//int (*returnColumnSizes)[2] = {1,1};*/
		}else
		{
			(*returnColumnSizes)[(*returnSize)-1]++;
			returnResult[(*returnSize)-1] = 
			realloc(returnResult[(*returnSize)-1],sizeof(char*)*(*returnColumnSizes)[(*returnSize)-1]);
			//第二個(原)字串群組的陣列,在裡面再新增一個字串(char*),(*returnColumnSizes)[(*returnSize)-1]是該群組目前元素個數
			returnResult[(*returnSize)-1][((*returnColumnSizes)[(*returnSize)-1])-1] =  myPairs[i].original;
			//新增字串進去(第二群組的第二個元素) => int (*returnColumnSizes)[2] = {1,1+1};
			
			/*returnResult[1] = realloc(returnResult[1],sizeof(char*)*2);	//第二個(原)字串群組的陣列,在裡面再新增一個字串(char*)
			returnResult[1][1] =  myPairs[i].original;	//新增字串進去(第二群組的第二個元素)
			(*returnColumnSizes)[1] = 2;	//int (*returnColumnSizes)[2] = {1,1+1};*/
		}
	}

	return returnResult;
}

int cmp_char(const void* _a , const void* _b)	//引數格式固定
{
	const char* a = (const char*)_a;	//強制型別轉換
	const char* b = (const char*)_b;
	return *a - *b;
}

int cmp_strPair(const void* _a , const void* _b)	//引數格式固定
{
	const strPair* a = (const strPair*)_a;	//強制型別轉換
	const strPair* b = (const strPair*)_b;
	return strcmp(a->sorted,b->sorted);	//a->sorted,b->sorted用這兩個字串來決定 myPairs[i]誰大
}







