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
	
	//situation 1:�̪����|���g�Lroot,=>����̪�"�`��"+�k��̪�"�`��"
	int max = maxDepth(root->right) + maxDepth(root->left);
	
	//situation 2:�̪����|�S���g�Lroot,=>��W����γ�W�k�䪺�̪����|
	int right = diameterOfBinaryTree(root->right);
	int left = diameterOfBinaryTree(root->left);

	//�T�̤��,���̤j
	if(right > max)
		max = right;
	if(left > max)
		max = left;
	
	return max;
}

