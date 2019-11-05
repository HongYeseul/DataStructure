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

void shortest_path(GraphType *g, int v){
    
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

    for(int i=0 ; i<g.n ; i++){
        printf("%d ",distance[i]);
    }printf("\n");
    return 0;
}

