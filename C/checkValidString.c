#include<stdio.h>
#include<string.h>
#include<stdbool.h>

_Bool checkValidString(char* str);

int main()
{
	char str[] = "(()(*)*(**)))";
	printf("%d",checkValidString(str));
}

//		(((**(**)))
//	  i:     ^
//	  j:        ^        
_Bool checkValidString(char* str)
{
	int len = strlen(str);
	int lastLeft = -1;
	int firstRight = -1;
	int left = 0;
	int right = 0;
	int star_left = 0;
	int star_right = 0;
	int star_middle = 0;
	
	for(int i=0;i < len;i++)
	{
		if(str[i] == ')')
		{
			firstRight = i;
			break;
		}
	}
	for(int i=0;i < len;i++)
	{
		if(str[i] == '(')
		{
			left++;
			lastLeft = i;
		}	
	}
	
	if(lastLeft == firstRight)
	{
		printf("1");
		return true;
	}
	
	if(lastLeft > firstRight)
	{
		printf("2");
		return false;
	}
		
	if(lastLeft < firstRight && lastLeft == -1)
	{
		printf("3");
		return false;
	}
		
	
	for(int i=0;i < len;i++)
	{
		if(str[i] == ')')
			right++;
		else if(i < lastLeft && str[i] == '*')
			star_left++;
		else if(i > firstRight && str[i] == '*')
			star_right++;
		else if(str[i] == '*')
			star_middle++;
	}
	printf("left:%d , right:%d , str_left:%d , str_right:%d , str_mid:%d\n",left,right,star_left,star_right,star_middle);
	if(right == left)
		return true;
	if(right > left)
	{
		if(star_left + star_middle + left >= right)
		{
			printf("4");
			return true;
		}
	}
	else if(star_right + star_middle + right >= left)
		{
			printf("5");
			return true;
		}
	printf("6");		
	return false;
}