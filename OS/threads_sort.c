#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10


void merge(int arr[],int min,int mid,int max)
{
  int tmp[SIZE];
  int i,j,k,m; 
  j=min;
  m=mid+1;
  for(i=min; j<=mid && m<=max ; i++)
  {
     if(arr[j]<=arr[m])
     {
         tmp[i]=arr[j];
         j++;
     }
     else
     {
         tmp[i]=arr[m];
         m++;
     }
  }
  if(j>mid)
  {
     for(k=m; k<=max; k++)
     {
         tmp[i]=arr[k];
         i++;
     }
  }
  else
  {
     for(k=j; k<=mid; k++)
     {
        tmp[i]=arr[k];
        i++;
     }
  }
  for(k=min; k<=max; k++)
     arr[k]=tmp[k];
}

void part(int arr[],int min,int max)
{
 int mid;
 if(min<max)
 {
   mid=(min+max)/2;
   part(arr,min,mid);
   part(arr,mid+1,max);
   merge(arr,min,mid,max);
 }
}

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

void* sort(void*arr){
	
	qsort(arr,SIZE/2,sizeof(int),cmpfunc);
	return 0;
}


int main(){

	int k;
	int arr[SIZE];
	int i;
	for(i=SIZE-1;i>=0;i--){
			int k = rand() % 20;
			arr[i]=k;
	}   
	
	printf("Razburkaniq masiv\n");
	for(i=0;i<SIZE;i++){
		printf("%d ",arr[i]);
	}
	
	pthread_t threads[2];
	
	int pesho,gosho;
	
	pesho=pthread_create(&threads[0],NULL,sort,(void*)arr); 
	
	if (pesho!=0){
		perror("error with create");
	}

	pthread_join(threads[0],NULL);
	
	printf("\nPodredenata purva chast\n");
	
	for(i=0;i<SIZE/2;i++){
		printf("%d ",arr[i]);
	}
	
	gosho=pthread_create(&threads[1],NULL,sort,&arr[(SIZE/2)]); 
	if (gosho!=0){
		perror("error with create");
	}
	
	pthread_join(threads[1],NULL);
	
	printf("\nPodredenata vtora chast\n");
	
	for(i=SIZE/2;i<SIZE;i++){
		printf("%d ",arr[i]);
	}
	
	part(arr,0,SIZE-1);
	
	printf("\nCeliq Podreden MAsiv\n");
	
	for(i=0;i<SIZE;i++){
		printf("%d ",arr[i]);
	}
	
	

	pthread_exit(NULL);
	return 0;
}
