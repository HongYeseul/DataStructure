#include <stdio.h>
#include <malloc.h>

int* func(){
    int *arr;

    arr = (int *)malloc(sizeof(int*)*10);

    for(int i=0; i<10 ; i++)
        arr[i] = i;
    return arr;
}

int main(){
    int *array;

    array = func();
    for(int i=0; i<10 ; i++){
        printf("%d ", array[i]);
    }

    free(array);
    return 0;
}
