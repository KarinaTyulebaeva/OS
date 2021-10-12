#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(){
    for(int i = 0; i < 10;i++){
    int * a = calloc(2560*sizeof(int));
    memset(a,0,sizeof(int)*2560);
    sleep(1);
    }
}
