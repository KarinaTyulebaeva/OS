#include<stdio.h>
#include<pthread.h>

#define N 10

char s[N];
int Pos;
int consumerS,producerS;
long long int t;

void* Consume(void *x){
    while(1)
    {
        if (consumerS)
        continue;

        if(Pos == 0){
            consumerS =1;
            producerS =0;
            continue;
        }
        printf("%c",s[Pos]);
        Pos--;
    }
    pthread_exit(NULL);
    return NULL;
}
void* Produce(void *x){
while(1){
    if (producerS)
    continue;
    if (Pos==10){
        consumerS=0;
        producerS=1;
        printf("done production with time %lld\n",t++);
        continue;
    }
    s[Pos]='a'+ Pos;
    Pos++;
}
pthread_exit(NULL);
return NULL;
}

int main(){
    consumerS=1;
    pthread_t producerS, consumerS;
    pthread_create(&producerS,NULL,Produce,NULL);
    pthread_create(&consumerS,NULL,Consume,NULL);
    while(1);
    return 0;
}
