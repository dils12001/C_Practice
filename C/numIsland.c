#include<stdio.h>

int numIsland(char** grid,int gridSize,int* gridColSize);
void checkLand(char** grid,int i,int j,int row,int col);
void printGrid(char** grid,int row,int col);

int main()
{
	char* grid[4];
	char a[] = {"11110"};
	grid[0] = a;
	char b[] = {"11100"};
	grid[1] = b;
	char c[] = {"10111"};
	grid[2] = c;
	char d[] = {"01000"};
	grid[3] = d;
	
	int gridColSize = 5;
	printf("%d\n",numIsland(grid,4,&gridColSize));	
}

int numIsland(char** grid,int gridSize,int* gridColSize)
{
	int count = 0;
	for(int i=0;i < gridSize;i++)
	{
		for(int j=0;j < *gridColSize;j++)
		{
			//printf("%c",grid[i][j]);
			if(grid[i][j] == '1')
			{
				checkLand(grid,i,j,gridSize,*gridColSize);
				printf("\n-----\n");
				printGrid(grid,4,5);
				printf("\n-----\n");
				count++;
			}
		}
	}
	printf("\ncount = %d\n",count);
	return count;
}

void checkLand(char** grid,int i,int j,int row,int col)
{
	if(i >= 0 && i < row && j >=0 && j < col)
	{
		if(j-1 >= 0 && grid[i][j-1] == '1')
		{
			grid[i][j-1] = '0';
			checkLand(grid,i,j-1,row,col);
		}
		if(j+1 < col && grid[i][j+1] == '1')
		{
			grid[i][j+1] = '0';
			checkLand(grid,i,j+1,row,col);
		}
		if(i-1 >= 0 && grid[i-1][j] == '1')
		{
			grid[i-1][j] = '0';
			checkLand(grid,i-1,j,row,col);
		}	
		if(i+1 < row && grid[i+1][j] == '1')
		{
			grid[i+1][j] = '0';
			checkLand(grid,i+1,j,row,col);
		}
	}
}

void printGrid(char** grid,int row,int col)
{
	for(int i=0;i < row;i++)
	{
		for(int j=0;j < col;j++)
			printf("%c",grid[i][j]);
		printf("\n");
	}	
}
