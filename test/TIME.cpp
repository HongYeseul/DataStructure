#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <algorithm>
using namespace std;

#define MAX_SIZE 100000000
#define INDEX_SIZE 10000000

int list[MAX_SIZE+1];

void print_arr(int n){
	printf("list >> ");
	for(int i=0; i<n ; i++){
		printf("%d ",list[i]);
	}printf("\n");
}

int seq_search(int key, int low, int high)
{ 
	int i;
	list[high+1] = key;  // 키 값을 찾으면 종료  
	for(i=low; list[i] != key; i++) 
		;
	if(i==(high+1)) return -1;  // 탐색 실패 
	else     return i;          // 탐색 성공 
}

int search_binary(int key, int low, int high)
{
	int middle;
	while( low <= high ){ 				// 아직 숫자들이 남아 있으면
		middle = (low+high)/2;
		if( key == list[middle] ) return middle; 	// 탐색 성공
		else if( key > list[middle] ) low = middle+1; 	// 왼쪽 부분리스트 탐색
		else high = middle-1; 			// 오른쪽 부분리스트 탐색
	}
 	return -1; 					// 탐색 실패
}

//search_index
int index_N = 0;

typedef struct{
	int key;
	int index;
}itable;

itable index_list[INDEX_SIZE];

int search_index(int key, int n){
	int i, low, high;
	
	if(key < list[0] || key > list[n-1])
		return -1;
	
	for(i=0 ; i< index_N ; i++){
		if(index_list[i].key < key && index_list[i+1].key > key)
			break;
	}
	if(i==index_N){
		low=index_list[i-1].index;
		high = n;
	}
	else{
		low = index_list[i].index;
		high = index_list[i+1].index;
	}
	
	
	return seq_search(key, low, high);
}

void make_index_list(int n){
	
	for(int i=0 ; i<n ; i++){
		if(i%200 == 0){
			index_list[index_N].index = i;
			index_list[index_N++].key = list[i];
		}
	}
}

void index_print(){
	printf("index list : ");
	for(int i=0; i<index_N; i++){
		printf("%d ", index_list[i].key);
	} printf("\n");
}

// interpol 보간 
int interpol_search(int key, int n)
{
	int low, high, j;

	low = 0;
	high = n - 1;
	while ((list[high] >= key) && (key > list[low])) {
		j = ((float)(key - list[low]) / (list[high] - list[low])
			*(high - low)) + low;
		if (key > list[j]) low = j + 1;
		else if (key < list[j]) high = j - 1;
		else low = j;
	}
	if (list[low] == key) return(low);  // 탐색성공
	else return -1;  // 탐색실패
}


//END

double seq_search_t(int key, int low, int high){
	
	struct timeval startTime, endTime;
   	double diffTime;
	
	gettimeofday(&startTime, NULL);
	
	int index =  seq_search(key, low, high);
	if(index == -1){
		printf("없음\n");
	}
	else
		printf("%d 번째에 있음\n", index+1);
		
	gettimeofday(&endTime, NULL);
	printf("%f %f %f %f\n", (double)endTime.tv_sec , (double)endTime.tv_usec / 1000000.0 , (double)startTime.tv_sec , (double)startTime.tv_usec / 1000000.0);
   	diffTime = (double)endTime.tv_sec + (double)endTime.tv_usec / 1000000.0 - (double)startTime.tv_sec - (double)startTime.tv_usec / 1000000.0;
  	printf("Seq_search : %f s\n", diffTime);
 	return diffTime;
}

double binary_search_t(int key, int low, int high){
	
	struct timeval startTime, endTime;
   	double diffTime;
	
	gettimeofday(&startTime, NULL);
	
	int index = search_binary(key, low, high);
	if(index == -1){
		printf("없음\n");
	}
	else
		printf("%d 번째에 있음\n", index+1);
	
	gettimeofday(&endTime, NULL);
	printf("%f %f %f %f\n", (double)endTime.tv_sec , (double)endTime.tv_usec / 1000000.0 , (double)startTime.tv_sec , (double)startTime.tv_usec / 1000000.0);
   	diffTime = (double)endTime.tv_sec + (double)endTime.tv_usec / 1000000.0 - (double)startTime.tv_sec - (double)startTime.tv_usec / 1000000.0;
  	printf("Binary_search : %f s\n", diffTime);
 	return diffTime;
}

double search_index_t(int key, int n){
	
	
	make_index_list(n);
	
	struct timeval startTime, endTime;
   	double diffTime;
	gettimeofday(&startTime, NULL);
	
	int index = search_index(key, n);
	if(index == -1)
		printf("없음\n");
	else
		printf("%d번째에 있음\n", index+1);
	
	gettimeofday(&endTime, NULL);
   	diffTime = (double)endTime.tv_sec + (double)endTime.tv_usec / 1000000.0 - (double)startTime.tv_sec - (double)startTime.tv_usec / 1000000.0;
  	printf("index_search : %f s\n", diffTime);
  	
 	return diffTime;
}

double interpol_search_t(int key, int n){

	struct timeval startTime, endTime;
   	double diffTime;
	gettimeofday(&startTime, NULL);
	
	int index = interpol_search(key, n);
	if(index == -1)
		printf("없음\n");
	else
		printf("%d번째에 있음\n", index+1);
	
	gettimeofday(&endTime, NULL);
   	diffTime = (double)endTime.tv_sec + (double)endTime.tv_usec / 1000000.0 - (double)startTime.tv_sec - (double)startTime.tv_usec / 1000000.0;
  	printf("interpol_search : %f s\n", diffTime);
  	
 	return diffTime;
}

int main(void){
	
	double seq, binary, search, interpol;
	
	int n;
	scanf("%d",&n);
	
	srand(time(NULL));
	int key = rand()%n;
	printf("key값은 %d\n", key);
	for(int i=0; i<n ; i++){
		list[i] = rand()%n;
	}
	
	if(n <= 100)
		print_arr(n);
	
	seq = seq_search_t(key, 0, n);
	
	sort(list, list+(n));
	
	printf("sorted \n");
	if(n<= 100)
		print_arr(n);
	
	binary = binary_search_t(key,0, n);

	search = search_index_t(key, n);
//	index_print();
	interpol = interpol_search_t(key, n);
	
	printf("seq %f, binary %f, search %f, interpol %f\n", seq, binary, search, interpol);
	
	return 0;
}
