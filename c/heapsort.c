#include<stdio.h>
#include<stdlib.h>

void ADJUST1(int K[], int i, int n) {
    int KEY = K[i]; 
    int j = 2 * i;  
    while (j <= n) {
        if ( (j < n) && (K[j] < K[j+1]) ) j++ ;
        if (KEY > K[j]) {
            K[ j/2 ] = KEY;
            return;
        }
        K[ j/2 ] = K[j];
        j = j*2 ; 
    }
    K[ j/2 ] = KEY;
}

void ADJUST2(int K[], int i, int n) {
    int KEY = K[i]; 
    int j = 2 * i;  
    while (j <= n) {
        if ( (j < n) && (K[j] > K[j+1]) ) j++ ;
        if (KEY < K[j]) {
            K[ j/2 ] = KEY;
            return;
        }
        K[ j/2 ] = K[j];
        j = j*2 ; 
    }
    K[ j/2 ] = KEY;
}

void HeapSort(int K[], int n) {
    int i;
    for (i = n/2 ; i >=1; i--)
        ADJUST2(K, i, n);

    for (i = n-1; i >= 1; i--) {
        int tmp = K[1];
        K[1] = K[i+1] ;
        K[i+1] = tmp;
        ADJUST2(K, 1, i );
    }
}

int main(){
    int A[10]={0,5,1,4,7,4,6,9,3,7};
    HeapSort(A,9);
    for(int i=1;i<10;i++) printf("%d", A[i]);
}