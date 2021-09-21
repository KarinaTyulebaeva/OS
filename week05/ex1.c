#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* print_thread(void* ptr){
    printf("Thread[%d] ", *(int*)ptr);
    pthread_exit(&*(int*)ptr);
    return 0;
}

int main(){
    const int N = 5;
    pthread_t threads[N];
    for(int i =0; i < N; i++){
        printf("Thread[%d] created.\n", i);
        int* t =&i;
        
        pthread_create(&threads[i], NULL, print_thread, (void *)t);
        pthread_join(threads[i], NULL);
        printf("Thread finished.\n");
    }
    return 0;
}
