#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>



typedef struct sized_array{

	int *pArray;
	int size;

} sized_array;



int sum(int*arr,int size){
	if(size==1){
		return arr[0];
	} 
	else if(size==2){
		return (arr[0]+arr[1]);
	
	}
	return (sum(arr,size/2)+sum(arr+size/2,size/2));
}

int main(){


int arr[8]={1,2,3,4,5,6,7,8};
int size=8;

	
	int s=sum(arr,size);
	printf("%d\n",s);

	return 0;
}
