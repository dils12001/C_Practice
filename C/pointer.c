#include<stdio.h>

int main(){
	int v[2][3] = { {1,2,3},{4,5,6} };
	int * a = &v[0][0];
	int** pointer = &a;
	printf("%d\n", *(*pointer));
	printf("%d\n",111);
	int b = *(*(pointer+0)+5);
	//由於*pointer是指到a,而a的下一格是什麼,我不知道,故不能用*(pointer+i)來表示v[i]的值
	//但可以用*(*pointer+i)來表示v[0][i]的值	(甚至指到i=5,因為我們知道其實號面還有資料)
	printf("%d\n", b);
	printf("%d\n",222);
}