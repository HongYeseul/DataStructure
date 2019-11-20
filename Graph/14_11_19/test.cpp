#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
#define MAX_SIZE 10
void print_list(int list[], int n){
    if(n <= 100){
        for(int i=0; i<n ; i++)
        printf("%d ", list[i]);
    
    }
}

void selection_sort(int list[], int n)
{   int i, j, least, temp;
    for(i=0; i<n-1; i++) {
            least = i;
            for(j=i+1; j<n; j++)            // 최솟값 탐색
                if(list[j]<list[least]) least = j;
            SWAP(list[i], list[least], temp);
        }
    if(n <= 100)
         printf("\nselection sort > ");
    print_list(list, n);
}

void insertion_sort(int list[], int n){
    int i, j, key;
    for(i=1; i<n ; i++){
        key = list[i];
        for(j=i-1 ; j>=0 && list[j]> key ; j++)
            list[j+1] = list[j];
        list[j+1] = key;
    }
    if(n <= 100)
         printf("\ninsertion sort > ");
    print_list(list, n);
}
void bubble_sort(int list[], int n)
{  
   int i, j, temp;
   for(i=n-1; i>0; i--){
        for(j=0; j<i; j++)  // 앞뒤의 레코드를 비교한 후 교체
          if(list[j]>list[j+1])   
                    SWAP(list[j], list[j+1], temp);
      }
    if(n <= 100)
         printf("\nbouble sort > ");
    print_list(list, n);
}

int main(void)
{
        int i,n;
        srand(time(NULL));
        scanf("%d", &n);
        int list[n];
       for (i = 0; i<n; i++)       // 난수 생성 및 출력 
                list[i] = rand() % n; // 난수 발생 범위 0~99
         if(n <=100){
            for(int j=0 ; j<n ; j++)
                printf("%d ", list[j]);
         }           

         insertion_sort(list, n);
         selection_sort(list, n);
         bubble_sort(list,n);
    return 0;
}
