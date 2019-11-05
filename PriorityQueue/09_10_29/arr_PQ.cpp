#include <stdio.h>
#include <stdlib.h>
#define MAX 6

void MK_arr(int arr[], int data){
    int i=1, temp;

    while(1){
        if(arr[i] == 0){
            arr[i] = data;
            return;
        }
        else if(arr[i]> data){ // 루트가 더 클 때
            if(i==1) i*= 2;
            else if(arr[i] < arr[i+1]) i*=2;
            else if(arr[i] > arr[i+1]){
                temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
            }
        }
        else if(arr[i] < data){ // 루트가 더 작을 때
            temp = arr[i];
            arr[i] = data;
            data = temp;
        }
        
    }
}

int DL_arr(int arr[]){
    int i=1, num;
    if(arr[2] == 0 && arr[3] == 0){
        num = arr[i];
        arr[i] = 0;
        return num;
    }
    else num = arr[i];

    while(1){
        if(i*2 < MAX && arr[i*2 +1] != 0){
            arr[i] = arr[i*2+1];
            i= i*2 +1;
        }
        else if(i*2 < MAX && arr[i*2 +1] ==0){
            arr[i] = arr[i*2];
            i *= 2;
        }
        else{
            arr[i] = 0;
            return num;
        }
    }

}

int main(void){
    int data, num;
    int arr[MAX] = {0};

    for(int i=0 ; i< (MAX-1) ; i++){
        printf("%d 번째 데이터 입력 ",i+1);
        scanf("%d",&data);
        MK_arr(arr, data);
        
        printf(">> ");
        for(int j=1 ; j<MAX ; j++){
            printf("%d", arr[j]);
        } printf("\n");

    }

    for(int i=0 ; i< (MAX-1) ; i++){
        num = DL_arr(arr);
        printf("제일 큰 수 %d 삭제 >>", num);
        for(int j=1 ; j<MAX ; j++){
            printf("%d", arr[j]);
        } printf("\n");
    }

    return 0;
}
