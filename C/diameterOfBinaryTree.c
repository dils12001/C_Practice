#include<stdio.h>

typedef struct
{
	int val;
	treeNode* right;
	treeNode* left;
}treeNode;

int main()
{
	
}

int maxDepth(treeNode* root)
{
	if(root == NULL)
		return 0;
	int max = maxDepth(root->right)+1;
	if(maxDepth(root->left)+1 > max)
		max = maxDepth(root->left)+1;
	return max;
}


int diameterOfBinaryTree(treeNode* root)
{
	
	//situation 1:最長路徑有經過root,=>左邊最長"深度"+右邊最長"深度"
	int max = maxDepth(root->right) + maxDepth(root->left);
	
	//situation 2:最長路徑沒有經過root,=>單獨左邊或單獨右邊的最長路徑
	int right = diameterOfBinaryTree(root->right);
	int left = diameterOfBinaryTree(root->left);

	//三者比較,取最大
	if(right > max)
		max = right;
	if(left > max)
		max = left;
	
	return max;
}

