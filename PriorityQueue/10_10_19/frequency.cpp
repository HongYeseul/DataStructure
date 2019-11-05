#include <stdio.h>
#include <stdlib.h>
#include "huffman_tree.h"

#define MAX 200

typedef struct{
    int freq;
    char key;
}Element;

typedef struct{
    Element heap[MAX];
    int heap_size;
}Heaptype;


Heaptype* create1(){
    return (Heaptype*)malloc(sizeof(Heaptype));
}

void init1(Heaptype *h){
    h->heap_size = 0;
}

void insert_max_heap(Heaptype *h, Element item){
    int i;
    i = ++(h->heap_size);

    while((i!=1) && (item.freq > (h->heap[i/2]).freq)){
        h->heap[i] = h->heap[i/2];
        i/=2;
    }
    h->heap[i] = item;
}

Element delete_max_heap(Heaptype* h){
    int parent, child;
    Element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;

    while(child <= h->heap_size){
        if((child < h->heap_size) && (h->heap[child].freq) < h->heap[child+1].freq){
            child++;
        }
        if(temp.freq >= h->heap[child].freq) break;

        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

int main(void){
    Heaptype* heap;
    char arr[100];
    Element data[100] = {0};
    int FREQ[MAX] = {0};
    char CH_LIST[MAX] = {0};
    int cpy=0;

    heap = create1();
    init1(heap);

    printf("빈도 구할 문장 >> ");
    fgets(arr, 100, stdin);
    printf("인식 된 문장 >> %s\n", arr);
    
    int i=0;
    while(1){
        for(int j = 0 ; j < cpy+1 ; j++){
            if(data[j].key == arr[i]){
                data[j].freq++;
                break;
            } 

            else if(data[j].key == 0 ){
              data[j].key = arr[i];
              data[j].freq = 1;
              cpy++;
              break;
            }
        }
        i++;

        if(arr[i] == '\n') break;
    }
    
    printf("중복되지 않는 문자 %d개 출력\n",cpy);
    for(int i=0 ; data[i].key != 0 ; i++ ){
        printf("%c %d개 \n", data[i].key, data[i].freq);
    }
    printf("정렬 된 문자 %d개 출력\n",cpy);
    for(int i=0 ; i<cpy ; i++){
        insert_max_heap(heap, data[i]);
    }
    for(int i = 1 ; i< cpy ; i++){
        printf("%c ", heap->heap[i].key);
    }
    for(int i=0 ; i<cpy ; i++){
        Element hi;
        hi = delete_max_heap(heap);
        FREQ[i] = hi.freq;
        CH_LIST[i] = hi.key;
        printf("%c %d개\n",hi.key,hi.freq);
    }
    
    huffman_tree(FREQ, CH_LIST, cpy);
    

    return 0;
}
