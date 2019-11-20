#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES    1001
#define INF 100001  /* 무한대 (연결이 없는 경우) */

typedef struct GraphType {
    int n;  // 정점의 개수
    int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;
GraphType g;

int distance[MAX_VERTICES];/* 시작정점으로부터의 최단경로 거리 */
int found[MAX_VERTICES];        /* 방문한 정점 표시 */

void init_graph(){
    int i,j;
    for(i=0 ; i <= g.n ; i++){
            for(j=0 ; j<= g.n ; j++){
                        if(i==j) g.weight[i][j] = 0;
                        else g.weight[i][j] = INF;
                    }
        }
}

void input(int bus){
    int i, a,b,w;
    for(i=1 ; i<=bus ; i++){
            scanf("%d %d %d",&a , &b, &w);
            g.weight[a][b] = w;
        }
}

void setting_array(int v){
    int i;
    for(i=1 ; i<=g.n ; i++){
            distance[i] = g.weight[v][i];
            found[i] = FALSE;
        }
    found[v] = TRUE;
}

void print_graph(){
    int i,j;
    for(i=1 ; i<=g.n ; i++){
            for(j=1 ; j<=g.n ; j++){
                        printf("%d\t", g.weight[i][j]);
                    } printf("\n");
        }
}

int find_min(){
    int i;
    int index = -1, small = INF+1;
    for(i=1 ; i<= g.n ; i++){
            if(!found[i] && distance[i] < small){
                        small = distance[i];
                        index = i;
                    }
        }
    return index;
}

void shortest_path(){   // 배열들 setting 미리 해줬으므로 안해도 됨.
    int index,i ,j;
    
    for(i=1 ; i<=g.n ; i++){ // 1. 작은 index 찾기
            index = find_min(); 
            found[index] = TRUE;
            
            
            for(j=1 ; j<=g.n ; j++){ // 2. 값 더한 것과 비교해서 작으면 초기화 
                        if(found[j]) continue;
                        
                        if(distance[j] > distance[index] + g.weight[index][j]){
                                        distance[j] = distance[index] + g.weight[index][j];
                                    }
                    }
        }
}

void print_path(){
    int i;
    for(i=1 ; i<= g.n ; i++)
        printf("%d ",distance[i]);
    printf("\n");
}

int main(void){
    int bus;
    int start, finish;
    scanf("%d %d",&g.n, &bus);
        
    init_graph(); // graph 초기화 (INF 및 0 생성) 
    input(bus); // graph에 입력받아 초기화 
    
    scanf("%d %d",&start, &finish); //출발점 & 도착점 scan
    setting_array(start); //distance & found setting 
    

    
    shortest_path();
    printf("%d",distance[finish]); //답 
    
    return 0;
}
