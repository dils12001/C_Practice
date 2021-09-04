#include<stdio.h>
#include<conio.h>
void TOH(int n,char source,char target,char temp);
void main()
{
	int n;
	printf("nEnter number of plates:");
	scanf("%d",&n);
	printf("\t move method disk number \n");
	TOH(n,'A','B','C');
	getch();
}
void TOH(int n,char source,char target,char temp)
{
	if(n>0)
	{
		TOH(n-1,source,temp,target);
		printf("\t%c ==> %c\t\t%8d\n",source,target,n);
		TOH(n-1,temp,target,source);
	}
}