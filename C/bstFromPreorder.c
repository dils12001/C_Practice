#include<stdio.h>

typedef struct
{
	int val;
	treeNode* left;
	treeNode* right;
}treeNode;

int main()
{
	int preorder[] = {8,5,1,7,10,12};
	
}


//		[8,5,1,7,10,12]
//		      8
//		5	        10
//	  1   7     NULL  12
//return a tree [8,5,10,1,7,null,12]

treeNode* bstFromPreorder(int* preorder,int size)
{
	treeNode* myTree = malloc(sizeof(treeNode)*1);
	myTree[0]->val = preorder[0];
	
	if(preorder[0+1] < preorder[0])	//�����𪺸�,��쥪��root
	{
		myTree[0]->left->val = preorder[0+1];
		bstFromPreorder
	}	
		
	for(int i=1;i < size;i++)	//��k�𪺮�
	{
		if(preorder[i] > preorder[0])
		{
			myTree[0]->right->val = preorder[i];
			break;
		}
	}

}

void something(int* preorder,int i,int j)
{
	treeNode* myTree = malloc(sizeof(treeNode)*1);
	myTree[treeCount]->val = preorder[i];
	
	if(preorder[i+1] < preorder[i])	//�����𪺸�,��쥪��root
	{
		
		myTree[treeCount]->left->val = preorder[i+1];
		bstFromPreorder
	}	
		
	for(int i=1;i < size;i++)	//��k�𪺮�
	{
		if(preorder[i] > preorder[0])
		{
			myTree[0]->right->val = preorder[i];
			break;
		}
	}
	
}

