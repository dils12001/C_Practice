#include<stdio.h>

int minPathSum(int** grid,int gridSize,int* gridColSize);
int min(int a,int b);

int main()
{
	int temp[3][3]= {{1,3,1},
					  {1,5,1},
					  {4,2,1}};
	int* grid[3];
	grid[0] = temp[0];
	grid[1] = temp[1];
	grid[2] = temp[2];
	int gridColSize = 3;
	printf("%d",minPathSum(grid,3,&gridColSize));
}

int minPathSum(int** grid,int gridSize,int* gridColSize)
{
	for(int i=0;i < gridSize;i++)
	{
		for(int j=0;j < *gridColSize;j++)
		{
			if(i == 0 && j != 0)
				grid[i][j] += grid[i][j-1];
			else if(j == 0 && i != 0)
				grid[i][j] += grid[i-1][j];
			else if(i != 0 && j != 0)
				grid[i][j] += min(grid[i-1][j],grid[i][j-1]);
		}
	}
	return grid[gridSize-1][*gridColSize-1];
}
int min(int a,int b)
{
	int min = a;
	if(b < a)
		min = b;
	return min;
}