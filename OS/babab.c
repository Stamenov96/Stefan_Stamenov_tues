#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 2

int gold_in_mine = 50;
pthread_mutex_t sum_mutex;


void* sum(void* arg){
	int i=0;
	
	while(gold_in_mine>0){
		pthread_mutex_lock(&sum_mutex);
		if (gold_in_mine>0){
			printf("worker #%d entered the mine\n",(int)arg);
			//sleep(1);
			gold_in_mine -= 10;
			i+=10;
			pthread_mutex_unlock(&sum_mutex);
			printf("worker #%d exit the mine\n",(int)arg);
	}
	pthread_mutex_unlock(&sum_mutex);

	pthread_exit((void*)i);

}



int main(){
	pthread[NUM_THREADS] threads;
	
	pthread_mutex_itit(&sum_mutex,NULL);
	
	
	pthread_t first,second;
	
	pthread_create(&first,NULL,mine,(void*)1);
	pthread_create(&second,NULL,mine,(void*)2);

	pthread_join(first,NULL);
	pthread_join(second,NULL);
	
	printf("%d\n",common);

	pthread_mutex_destroy(&sum_mutex);
	
	return 0;
}
