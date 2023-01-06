#include<stdio.h>
#include<stdlib.h>

#define MAX 101

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
    
    printf("%d %d", n, source);
    //BFS_Path(___, ___, ___, 2);
    return 0;
}