#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>



typedef struct sized_array{

	int *pArray;
	int size;

};



int sum(array str){
	if(str.size==1){
		return str.pArray[0];
	} 
	else if(str.size==2){
		return (str.pArray[0]+str.pArray[1]);
	
	}
	return (sum(str.pArray,str.size/2)+sum(str.pArray+str.size/2,str.size/2));
}

int main(){


int arr[8]={1,2,3,4,5,6,7,8};
int size=8;

	
	sized_array
	
	//int s=sum(arr,size);
	//printf("%d\n",s);

	return 0;
}
