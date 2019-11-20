#include <stdio.h>

void merge(int list[], int left, int mid, int right){
    int nlist[right] = {0};
    int Bstart = mid+1;
    int i=0;

    while(1){
        if(list[left] < list[Bstart]){
            nlist[i++] = list[left++];
        }
        else{
            nlist[i++] = list[Bstart++];
        }
        if((left == (mid+1)) || (Bstart == (right + 1)))
            break;
    }

    if(left == (mid+1)){
        nlist[right] = list[right];
    }
    else{
        nlist[right] = list[mid];
    }
    
    for(i=0; i<=right ; i++){
        list[i] = nlist[i];
    }
}

int main(){
    int list[] = {1, 3, 7, 11, 2, 4, 6, 8};
    int left = 0;
    int right = 7;
    int mid = 3;

    merge(list, left, mid, right);
    
    for(int i=left ; i<= right ; i++){
        printf("%d ", list[i]);
    }
    return 0;
}
