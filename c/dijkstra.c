#include<stdio.h>
#include<stdlib.h>

#define INFINITY 99999
#define MAX 50

void dijkstra(int G[MAX][MAX], int n, int source)
{

    int c[MAX][MAX], d[MAX], p[MAX];
    int visited[MAX], count, mindistance, nextnode, i, j;

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(G[i][j]==0)
                c[i][j]= INFINITY;
            else
                c[i][j]=  G[i][j] ;

    for(i=0; i<n; i++)
    {
        d[i] = INFINITY ;
        p[i] = 0 ;
        visited[i] = 0;
    }

    d[source] = 0 ;
    visited[source] = 1;
    count = 1;

    while (count < n)
    {
        mindistance=INFINITY;

        for(i = 0; i < n; i++)
            if (d[i] < mindistance && visited[i] == 1 )
            {
                mindistance = d[i] ;
                nextnode = i ;
            }

        visited[ nextnode ] = 0;

        for (i=0; i<n; i++)
            if (visited[i] == 0 )
                if ( d[i] >  c[nextnode][i]+mindistance)
                {
                    d[i] = c[nextnode][i]+mindistance ;
                    p[i] = nextnode ;
                    visited[i]=1;
                }
        count++;
    }

    for(i=0; i<n; i++)
        if(i != source)
        {
            printf("\nDistance to node%d=%d", i, d[i] );
            printf("\nPath=%d", i);
            j = i;
            do
            {
                j = p[j] ;
                printf("<-%d",j);
            } while (j != source);
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

int main()
{
    int G[MAX][MAX], n, source;

    readData( "data.txt" , G , &n , &source);
    dijkstra( G , n , source );

    return 0;
}