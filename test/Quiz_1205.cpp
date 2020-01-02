#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define MAX 1000000
int N;
int arreven[MAX], arrodd[MAX];

void mk_arr(){
    printf("Input data size :");
    scanf("%d", &N);

    int j= 1;
    for(int i=0 ; i<N/2 ; i++){
        arrodd[i] = j;
        arreven[i] = j+1;
        j=j+2;
    }
    printf("%d odd numbers are generated\n", N/2);
}

void print_arr(){
    printf("\n 홀수 : ");
    for(int i=0 ; i<N/2 ; i++){
        printf("%d ", arrodd[i]);
    }
    printf("\n 짝수 : ");
    for(int i=0 ; i<N/2 ; i++){
        printf("%d ", arreven[i]);
    }
    printf("\n");
   
}

int search_binary(int key, int low, int high){
    int middle;
    while(low<=high){
        middle = (low+high)/2;
        if(key == arrodd[middle]) return middle;
        else if(key>arrodd[middle]) return middle+1;
        else high = middle -1;
    }
    printf("안됨 \n");
    return -1;
}
int seq_search(int key, int low, int high){
    for(int i=low ; i< high ; i++){
        if(arrodd[i] == key)
            return i;
    }
    return -1;
}

int S_search_binary(int key, int low, int high){
    int middle;
    while(low<=high){
        middle = (low+high)/2;
        if(key == arreven[middle]) return middle;
        else if(key>arreven[middle]) return middle+1;
        else high = middle -1;
    }
    printf("안됨 \n");
    return -1;
}
void fail_binary(){
    struct timeval startTime, endTime;
    double seq, bi;

    gettimeofday(&startTime, NULL);
    
    for(int i=0 ; i<N/2 ; i++){
        search_binary(arreven[i], 0, N/2);
    }
    
    gettimeofday(&endTime, NULL);
    bi = (double)endTime.tv_sec + (double)endTime.tv_usec / 1000000.0 - (double)startTime.tv_sec - (double)startTime.tv_usec / 1000000.0;
    

    gettimeofday(&startTime, NULL);

    for(int i=0 ; i<N/2 ; i++){
        seq_search(arreven[i], 0, N/2);
    }

    
    gettimeofday(&endTime, NULL);
    seq = (double)endTime.tv_sec + (double)endTime.tv_usec / 1000000.0 - (double)startTime.tv_sec - (double)startTime.tv_usec / 1000000.0;


    printf("Even numbers search time(fail)\n");
    printf("Seq Search Time : %f s\n", seq);
    printf("Bin Search Time : %f s\n", bi);
    printf("Bin Search %.0f X faster.\n", seq/bi);
}

void success_binary(){
    
    struct timeval startTime, endTime;
    double seq, bi;

    gettimeofday(&startTime, NULL);
    
    for(int i=0 ; i<N/2 ; i++){
        S_search_binary(arrodd[i], 0, N/2);
        
    }
    
    gettimeofday(&endTime, NULL);
    bi = (double)endTime.tv_sec + (double)endTime.tv_usec / 1000000.0 - (double)startTime.tv_sec - (double)startTime.tv_usec / 1000000.0;
    

    gettimeofday(&startTime, NULL);

    for(int i=0 ; i<N/2 ; i++){
        seq_search(arrodd[i], 0, N/2);
    }
    
    gettimeofday(&endTime, NULL);
    seq = (double)endTime.tv_sec + (double)endTime.tv_usec / 1000000.0 - (double)startTime.tv_sec - (double)startTime.tv_usec / 1000000.0;


    printf("Even numbers search time(success)\n");
    printf("Seq Search Time : %f s\n", seq);
    printf("Bin Search Time : %f s\n", bi);
    printf("Bin Search %.0f X faster.\n", seq/bi);
}

    

int main(void){
    int arr[MAX];

    mk_arr();
   // print_arr();
    
    fail_binary();
    success_binary();
    
    return 0;
}
