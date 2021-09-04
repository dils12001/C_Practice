#include<stdio.h>
#include<string.h>

char* stringShift(char* s,int** shift,int shiftSize);

int main()
{
	int shift[6][2] = { {1,5},{0,2},{1,3},{0,5},{0,4},{1,6} };
	int* shiftPoint[6];
	for(int i=0;i < 6;i++)
		shiftPoint[i] = shift[i];
	char str[] = "abcdefg";
	printf("%s",stringShift(str,shiftPoint,6));
}

char* stringShift(char* s,int** shift,int shiftSize)
{
	int moveLeft = 0;
	//int moveRight = 0;	¥k²¾i®æ = ¥ª²¾(strlen(s)-i)®æ
	
	for(int i=0;i < shiftSize;i++)
	{
		if(shift[i][0] == 0)
			moveLeft += shift[i][1];//¥ª²¾
		else
			moveLeft += (strlen(s) - shift[i][1]);
			//moveRight += shift[i][1];//¥k²¾
	}
	
	moveLeft = moveLeft % strlen(s);
	
	char temp[strlen(s)+1];
	strcpy(temp,s);
	/*
	0 1 2 3 4
	a b c d e
	c d e a b
	¥ª²¾2®æ
	s[0] = t[2]
	s[1] = t[3]
	s[2] = t[4]
	s[3] = t[0]
	s[4] = t[1]
	*/
	int index;

	for(int i=0;i < strlen(s);i++)
	{
		index = (i+moveLeft)%strlen(s);
		s[i] = temp[index];
		printf("s[%d] = %c ,temp[%d]\n",i,s[i],index);
	}
	return s;
}