#include <stdio.h>

int seq_search(int arr[], int val, int size){
    for(int i=0; i<size; i++){
        if(arr[i] == val){
            printf("%d번째 찾음!", i+1);
            return arr[i];
        }
    }
    printf("존재하지 않음");
    return 0;
}

int binary_search(int arr[], int val, int size){
    
    int i=size/2;

    while(1){

        if(arr[i] > val)
            i/=2;
        else if(arr[i]<val)
            i*=2;
        else if(arr[i] == val)
            return i;

        if(i== size) break;
    }
    return -1;

}

int main(void){
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    
    int dap = -1;
    dap = binary_search(arr,10 , 10);
    if( dap != -1)
        printf("binary - dap : %d번째 위치 \n", dap+1);
    else
        printf("찾는 값 없음\n");

    return 0;
}
