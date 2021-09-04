#include<stdio.h>
#include <stdlib.h>

int wayOfWalk(int a,int b);

int main()
{
	int a;
	int b;
	printf("      0   1   2   3   4   5  \n"
		   "    ------------------------ \n"
		   " 0 | me |   |   |   |   |   |\n"
   		   "    ------------------------ \n"
		   " 1 |    |   |   |   |   |   |\n"
		   "    ------------------------ \n"
		   " 2 |    |   |   |   |   |   |\n"
		   "    ------------------------ \n"
		   " 3 |    |   |   |   |   |   |\n"
		   "    ------------------------ \n"
		   " 4 |    |   |   |   |   |   |\n"
		   "    ------------------------ \n"
		   " 5 |    |   |   |   |   |   |\n"
		   "    ------------------------ \n");
	printf("如上圖[可超過(5,5)]，要從(0,0)走到哪呢?\n"
		   "每次只能\"往右走2格\" or \"往下走1格\"");
	scanf("%d",&a);
	scanf("%d",&b);
	printf("走到map(%d,%d)有%d種可能",a,b,wayOfWalk(a+1,b+1));	
}
						//a = 4, b = 8	
int wayOfWalk(int a,int b)
{
	int** map = (int**)malloc(a*sizeof(int*));
	map = calloc(a,sizeof(int*));
	for (int j = 0;j < b;j++)
	{
		map[j] = (int*)malloc(b*sizeof(int));
		map[j] = calloc(b,sizeof(int));
	}
	
	//map[0][0] = 1;
	//for(int i = 1;i < a;i++)
		//map[i][0] = 1;
	//for(int j = 1;j < b;j++)
		//map[0][j] = 1;
	
	for(int i = 0;i < a;i++)
	{
		for(int j = 0;j < b;j++)
		{
			if(i == 0 || j == 0)
				map[i][j] = 1;
			else if(j%2 == 1)
				map[i][j] = 0;
			else
				map[i][j] = map[i-1][j] + map[i][j-2];
			//printf("%d\n",map[i][j]);
		}
	}
	int way = map[a-1][b-1];
	//printf("%dggggggg\n",way);
	for (int i = 0; i < b; i++) //記得釋放空間
		free(map[i]);
	free(map);
	return way;
}