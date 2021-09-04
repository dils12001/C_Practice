#include <stdlib.h>
#include<stdio.h>

void subArrayMaxSum(int* nums,int size,int* result);

int main(){
	int interger[] = {-2,1,-3,4,-1,2,1,-5,4};	//初始化一數字陣列,找出最大的連續子陣列和
	int* result;
	result = (int*)malloc(sizeof(int)*3);	//動態配置int[3],之後fuction直接將結果存入
	subArrayMaxSum(interger,9,result);	//引數說明:預計算之陣列,陣列大小,儲存結果之陣列
	printf("start: %d\nend: %d\nMaxSum: %d",result[0],result[1],result[2]);
	free(result);
}


void subArrayMaxSum(int* nums,int size,int* result){
	//作法思路:因為是算連續順序的加總,可算出到上一個陣列元素的最佳(大)解(和)
	//,若前一個陣列的最佳和是"負數",那麼本次元素加上上次最佳解一定會變小
	//,故本次的最佳解極為自己本身
	int firstIndex = 0;	//記錄該次最佳解的起始index,放入bestMaxSum[i][0]裡
	int bestMaxSum[size][2];	//每輪最佳解{最佳解的起始元素,最佳解(最大和)}
	bestMaxSum[0][0] = 0;
	bestMaxSum[0][1] = nums[0];
	for(int i = 1;i < size;i++){
		if(bestMaxSum[i-1][1] < 0){
			bestMaxSum[i][0] = i;
			bestMaxSum[i][1] = nums[i];
			}
		else{
			bestMaxSum[i][0] = bestMaxSum[i-1][0];
			bestMaxSum[i][1] = bestMaxSum[i-1][1] + nums[i];
		}	
	}
	
	int wantIndex = 0;
	for(int i = 1;i < size;i++){	//找出真正的最佳解(最大和)
		if(bestMaxSum[wantIndex][1] < bestMaxSum[i][1])
			wantIndex = i;
	}
	
	result[0] = bestMaxSum[wantIndex][0];
	result[1] = wantIndex;
	result[2] = bestMaxSum[wantIndex][1];
}