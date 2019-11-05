#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES    100 
#define INF 1000000 /* 무한대 (연결이 없는 경우) */

typedef struct GraphType {
    int n;  // 정점의 개수
    int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int distance[MAX_VERTICES];/* 시작정점으로부터의 최단경로 거리 */
int found[MAX_VERTICES];        /* 방문한 정점 표시 */

void setting(GraphType *g, int v){
    for(int i=0 ; i<g->n ; i++){
        distance[i] = g->weight[v][i];
        found[i] = FALSE;
    }
    found[v] = TRUE;
}

void print_path(GraphType *g){
    for(int i=0 ; i < g->n ; i++){
        printf("%d ", distance[i]);
    }printf("\n");
}

int search_min(GraphType *g){
    int index = -1, small = INF;
    
    for(int i=0; i < g->n ; i ++){
        if(small > distance[i] && !found[i]){
            index = i;
            small = distance[i];
        }
    }
    return index;
}

void shortest_path(GraphType *g, int v){
    //1. 세팅
    setting(g, v);
    //2. 작은 값을 계속 찾아 나간다.
    for(int i=0 ; i<g->n-1 ; i++){
        int index = search_min(g);
        found[index] = TRUE;
        print_path(g);

        //3. 더 작으면 dist에 넣는다.
        for(int j=0 ; j<g->n ; j++){
            if(found[j]) continue;

            if(distance[j] > distance[index] + g->weight[index][j])
                distance[j] = distance[index]+g->weight[index][j];
        }
    }
}

int main(void)
{
    GraphType g = { 7,
        {{ 0,  7,  INF, INF,   3,  10, INF },
            { 7,  0,    4,  10,   2,   6, INF },
            { INF,  4,    0,   2, INF, INF, INF },
            { INF, 10,    2,   0,  11,   9,   4 },
            { 3,  2,  INF,  11,   0, INF,   5 },
            { 10,  6,  INF,   9, INF,   0, INF },
            { INF, INF, INF,   4,   5, INF,   0 } }
        };
    shortest_path(&g, 0);
    return 0;
}
