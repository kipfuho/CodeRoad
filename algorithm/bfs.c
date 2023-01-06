#include<stdio.h>
#include<stdlib.h>
#include "queue.c"

#define MAX 101

int path[MAX];

void breadthFirstSearch(int g[MAX][MAX], int n, int source) {
    int visited[MAX];
    int i, cur;

    Queue *q = malloc(sizeof(Queue));
    q->ll.size = 0;
    q->ll.head=NULL;

    for(i=0; i<n; i++) visited[i] = 0;
    for(i=0; i<n; i++) path[i] = -1;

    cur = source;
    visited[cur] = 1;
    enqueue(q, cur);

    while (!isEmptyQueue(q)) {
        cur = dequeue(q);
        printf("%d ", cur);
        for (i = 0; i < n; i++)
            if (g[cur][i] != 0 && visited[i] == 0) {
                visited[i] = 1;
                path[i]=cur;
                enqueue(q, i);
            }
    }
}

void BFS_Path(int G[MAX][MAX], int n, int start, int end){
    int temp[n];
    int i=0, j=end;
    while(path[j]!=-1){
        temp[i++]=path[j];
        if(path[j]==start) break;
        j=path[j];
    }
    if(temp[i-1]!=start) printf("no path found");
    else{
        while(i>0){
            printf("%d ", temp[--i]);
        }
        printf("%d\n", end);
    }
}

void readData(char* filename, int G[MAX][MAX], int* pn, int* psource) {
    FILE* file = fopen (filename, "r");
    int i, j;
    if (file != NULL) {
        fscanf (file, "%d %d", pn, psource);
        for (i = 0; i < *pn; i++)
            for (j = 0; j < *pn; j++)
                fscanf(file, "%d", &G[i][j]);
    }
    fclose (file);
}

int main(void) {
    int G[MAX][MAX], n, source;
    readData("data.txt", G, &n , &source );
    breadthFirstSearch(G, n, source);
    printf("\n");  
    BFS_Path(G, n, 0, 11);
    return 0;
}