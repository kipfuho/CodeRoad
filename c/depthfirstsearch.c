#include<stdio.h>
#include<stdlib.h>

#define MAX 101

int G[MAX][MAX], visited[MAX];
int n, source;

void depthFirstSearch(int v) {
    int w;
    visited[v] = 1 ;

    printf("%d ", v );

    for (w = 0; w < n; w++)
        if (G[v][w] != 0  && visited[w] == 0 ) {
            depthFirstSearch( w );
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
    int i;
    readData( "data.txt" , G , &n , &source);

    for(i=0; i<n; i++)
        visited[i] = 0;

    depthFirstSearch( source );

    return 0;
}