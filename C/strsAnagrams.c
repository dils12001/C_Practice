#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp_char(const void* _a , const void* _b);
int cmp_strPair(const void* _a , const void* _b);
char*** groupAnagrams(char** strs,int strsSize,int* returnSize,int** returnColumnSizes);


typedef struct
{
	char* original;	//��l�r��
	char* sorted;	//�ƧǹL���r��
}strPair;	//�����ۭq�q�@�ӰΦWstruct,�ó]�w�O�W��strPair,�Y�ŧi�ɪ����ϥ�strPair��type�W

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
		strcpy(sorted_temp,strs[i]); 	//����strs[i]�ƻs��sorted_temp
		qsort(sorted_temp,strlen(strs[i]),sizeof(char),cmp_char);	//�A��sorted_temp�Ƨ�	

		myPairs[i].original = strs[i];	//myPairs[i].original����strs[i]
		myPairs[i].sorted = sorted_temp;	//myPairs[i].sorted����sorted_temp
	}
	
	qsort(myPairs,strsSize,sizeof(strPair),cmp_strPair);
	
	/*for(int i=0;i < strsSize;i++)
		printf("original:%s  sorted:%s\n",myPairs[i].original,myPairs[i].sorted);*/
	
	char*** returnResult = NULL;
	*returnSize = 0;	//returnResult���}�C����[[char**],[char**],[]]���D����3 char**���r��}�C
	*returnColumnSizes = NULL;	//���U��char**�̪����� �ƥ�[1(bat),2(tan,nat),3(eat,ate,tea)]
	
	for(int i=0;i < strsSize;i++)
	{
		if(i == 0 || myPairs[i].sorted != myPairs[i-1].sorted)	//�Ĥ@�� �� �C�@���r���W�@�����P��,�s�W�@�Ӹs��
		{
			(*returnSize)++;	//�r��s�ե[1
			returnResult = realloc(returnResult,sizeof(char**)*(*returnSize));	//�A�s�W�@�Ӹs��(char**�r��}�C),realloc��2(1+1)
			returnResult[(*returnSize)-1] = malloc(sizeof(char*)*1);	//��?�Ӧr��s�ժ��}�C,�b�̭��s�W�@�Ӧr��(char*)
			returnResult[(*returnSize)-1][0] =  myPairs[i].original;	//�s�W�r��i�h(��?�s�ժ��Ĥ@�Ӥ���)
	
			*returnColumnSizes = realloc(*returnColumnSizes,sizeof(int)*(*returnSize));
			//�Ĥ@�Ӹs�զ��@�Ӥ���int (*returnColumnSizes)[1+1],(*returnColumnSizes)�������ƥص���?�Ӧr��s��
			(*returnColumnSizes)[(*returnSize)-1] = 1;	//int (*returnColumnSizes)[2] = {1,1};
			
			/*returnResult = malloc(sizeof(char**)*1);	//�s�W�@�Ӹs��(char**�r��}�C)
			returnResult[0] = malloc(sizeof(char*)*1);	//�Ĥ@�Ӧr��s�ժ��}�C,�b�̭��s�W�@�Ӧr��(char*)
			returnResult[0][0] =  myPairs[i].original;	//�s�W�r��i�h
			*returnSize = 1;	//�r��s�ե[1
			*returnColumnSizes = malloc(sizeof(int)*1);	//�Ĥ@�Ӹs�զ��@�Ӥ���int (*returnColumnSizes)[1]
			(*returnColumnSizes)[0] = 1;	//int (*returnColumnSizes)[1] = {1};
			
			
			returnResult = realloc(returnResult,sizeof(char**)*2);	//�A�s�W�@�Ӹs��(char**�r��}�C),realloc��2(1+1)
			returnResult[1] = malloc(sizeof(char*)*1);	//�ĤG�Ӧr��s�ժ��}�C,�b�̭��s�W�@�Ӧr��(char*)
			returnResult[1][0] =  myPairs[i].original;	//�s�W�r��i�h(�ĤG�s�ժ��Ĥ@�Ӥ���)
			*returnSize = 2;	//�r��s�զA�[1
			*returnColumnSizes = realloc(*returnColumnSizes,sizeof(int)*2);	//�Ĥ@�Ӹs�զ��@�Ӥ���int (*returnColumnSizes)[1+1]
			(*returnColumnSizes)[1] = 1;	//int (*returnColumnSizes)[2] = {1,1};*/
		}else
		{
			(*returnColumnSizes)[(*returnSize)-1]++;
			returnResult[(*returnSize)-1] = 
			realloc(returnResult[(*returnSize)-1],sizeof(char*)*(*returnColumnSizes)[(*returnSize)-1]);
			//�ĤG��(��)�r��s�ժ��}�C,�b�̭��A�s�W�@�Ӧr��(char*),(*returnColumnSizes)[(*returnSize)-1]�O�Ӹs�եثe�����Ӽ�
			returnResult[(*returnSize)-1][((*returnColumnSizes)[(*returnSize)-1])-1] =  myPairs[i].original;
			//�s�W�r��i�h(�ĤG�s�ժ��ĤG�Ӥ���) => int (*returnColumnSizes)[2] = {1,1+1};
			
			/*returnResult[1] = realloc(returnResult[1],sizeof(char*)*2);	//�ĤG��(��)�r��s�ժ��}�C,�b�̭��A�s�W�@�Ӧr��(char*)
			returnResult[1][1] =  myPairs[i].original;	//�s�W�r��i�h(�ĤG�s�ժ��ĤG�Ӥ���)
			(*returnColumnSizes)[1] = 2;	//int (*returnColumnSizes)[2] = {1,1+1};*/
		}
	}

	return returnResult;
}

int cmp_char(const void* _a , const void* _b)	//�޼Ʈ榡�T�w
{
	const char* a = (const char*)_a;	//�j��O�ഫ
	const char* b = (const char*)_b;
	return *a - *b;
}

int cmp_strPair(const void* _a , const void* _b)	//�޼Ʈ榡�T�w
{
	const strPair* a = (const strPair*)_a;	//�j��O�ഫ
	const strPair* b = (const strPair*)_b;
	return strcmp(a->sorted,b->sorted);	//a->sorted,b->sorted�γo��Ӧr��ӨM�w myPairs[i]�֤j
}







