#include<stdio.h>
#include <stdlib.h>

typedef struct
{
	int* data;	//[2,5,1,9,8]
	int* mins;	//[2,2,1,1,1]儲存每一輪的最小值
	int size;
}myStack;

myStack* stackCreate();
void freeStack(myStack* a);
void pushStack(myStack* a,int x);
void popStack(myStack* a);
int topStack(myStack* a);
int minStack(myStack* a);
void printStack(myStack* a);

int main()
{
	myStack* stack1 = stackCreate();
	
	pushStack(stack1,2);
	printf("min:%d\n",minStack(stack1));
	printf("top:%d\n",topStack(stack1));
	printStack(stack1);

	
	pushStack(stack1,5);
	printf("min:%d\n",minStack(stack1));
	printf("top:%d\n",topStack(stack1));
	printStack(stack1);

	
	pushStack(stack1,1);
	printf("min:%d\n",minStack(stack1));
	printf("top:%d\n",topStack(stack1));
	printStack(stack1);

	popStack(stack1);
	printf("min:%d\n",minStack(stack1));
	printf("top:%d\n",topStack(stack1));
	printStack(stack1);
	
	pushStack(stack1,9);
	printf("min:%d\n",minStack(stack1));
	printf("top:%d\n",topStack(stack1));
	printStack(stack1);

	
	pushStack(stack1,8);
	printf("min:%d\n",minStack(stack1));
	printf("top:%d\n",topStack(stack1));
	printStack(stack1);

	
	freeStack(stack1);
}


myStack* stackCreate()
{
	myStack* a = malloc(sizeof(myStack)*1);
	a->data = NULL;
	a->mins = NULL;
	a->size = 0;
	return a;
}

void freeStack(myStack* a)
{
	free(a->data);
	free(a->mins);
	free(a);
}

void pushStack(myStack* a,int x)
{
	a->size++;
	a->data = realloc(a->data,sizeof(int)*(a->size));
	a->mins = realloc(a->mins,sizeof(int)*(a->size));
	a->data[a->size-1] = x;
	
	if(a->size == 1 || a->mins[a->size-2] > x)
		a->mins[a->size-1] = x;
	else
		a->mins[a->size-1] = a->mins[a->size-2];
}

void popStack(myStack* a)
{
	a->size--;
}

int topStack(myStack* a)
{
	return a->data[a->size-1];
}

int minStack(myStack* a)
{
	return a->mins[a->size-1];
}

void printStack(myStack* a)
{
	printf("print all stack:\n");
	printf("a->size = %d\n",a->size);
	for(int i=0;i < a->size;i++)
		printf("a->data[%d] = %d\n",i,a->data[i]);
	printf("\n");
}