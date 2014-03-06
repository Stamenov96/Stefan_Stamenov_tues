#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 2

int gold_in_mine = 50;
pthread_mutex_t sum_mutex;


void* sum(void* arg){
	int i;
	
	while(gold_in_mine>0){
		pthread_mutex_lock(&sum_mutex);
		printf("worker #%d entered the mine\n"),(int arg));
		mine -= 10;
		i+=10;
		pthread_mutex_unlock(&sum_mutex);
		printf("worker #%d exit the mine\n"),(int arg));
		
	}


	pthread_exit(i);

}



int main(){
	pthread [NUM_THREADS] threads;
	
	pthread_mutex_itit(&sum_mutex,NULL);
	
	
	pthread_t first,second;
	
	pthread_create(&first,NULL,mine,(void*)1);
	pthread_create(&second,NULL,mine,(void*)2);

	pthread_join(first,NULL);
	pthread_join(second,NULL);
	
	printf("%d\n",common);

	pthread_,utex_destroy(&sum_mutex);
	
	return 0;
}
