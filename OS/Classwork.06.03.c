#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 2

int gold_in_mine = 50;
pthread_mutex_t sum_mutex;


void* sum(void* arg){
	int i;
	
	while(gold_in_mine>0){
		pthread_mutex_lock(&sum_mutex);
		printf("worker #%d entered the mine"),(int arg));
		mine -= 10;
		i+=10;
		pthread_mutex_unlock(&sum_mutex);
		
	}


	pthread_exit(i);

}



int main(){

	pthread_t first,second;
	
	pthread_create(&first,NULL,sum,NULL);
	pthread_create(&second,NULL,sum,NULL);

	pthread_join(first,NULL);
	pthread_join(second,NULL);
	
	printf("%d\n",common);
	
	return 0;
}
