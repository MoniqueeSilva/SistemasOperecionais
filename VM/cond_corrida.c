// Para compilá-lo utilise: gcc -o thread1 thread1.cpp -lpthread

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg);
int NUM_THREADS = 4;
int i;
int count;

int main() {

    pthread_t threads[NUM_THREADS];

    for (i = 0; i < NUM_THREADS; i++) {
        int res = pthread_create(&threads[i], NULL, thread_function, (void*) i);
    	
	if (res != 0) {
        	perror("Thread creation failed");
        	exit(EXIT_FAILURE);
    	}
    }

    for (i = 0; i < NUM_THREADS; i++) {
        int res = pthread_join(threads[i], NULL);
	if (res != 0) {
        	perror("Thread join failed");
        	exit(EXIT_FAILURE);
    	}else{
		 printf ("Thread %d terminou\n",i);
	}
    }

    printf("Count %d\n",count);
    exit(EXIT_SUCCESS);
}

void *thread_function(void *id) {
   int j;
    for(j = 0; j < 2000;j++){
    	count++;	
    }
}
