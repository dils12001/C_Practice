#include<stdio.h>
#include<string.h>
//#include<stdbool.h>

_Bool backspaceCompare(char* s,char* t);
void processStr(char* str);

int main()
{
	char s[10]; 
	char t[10];
	printf("Enter string S:");
	scanf("%s",s);
	printf("Enter string T:");
	scanf("%s",t);
	
	if(backspaceCompare(s,t))
		printf("S and T are equal.");
}


_Bool backspaceCompare(char* s,char* t)
{
	/* str: "ab#c###de#" 
	     i:   ^			read
	     j:  ^			write	因為read的資料,永遠不會被先write(i >= j)所以可以用同一個陣列做修改
	newStr:  a		*/
	processStr(s);
	processStr(t);
	return strcmp(s,t) == 0;
}

void processStr(char* str)
{
	int j= -1;
	for(int i=0;i < strlen(str);i++)
	{
		if(str[i] != '#')
		{
			j++;
			str[j] = str[i];
		}
		else if(j >= 0)
		{
			j--;
		}
	}
	str[j+1] = '\0';
	printf("%s\n",str);
}