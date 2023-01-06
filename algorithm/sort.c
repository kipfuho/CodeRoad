#include<stdio.h>
#include<stdlib.h>

void selection_sort(int k[], int n) {
    int i, j, m, x;
    for (i = 0 ; i < n - 1 ; i++) {
        m = i ;
        for (j = i+1; j < n ; j++)
            if ( k[j] < k[m] ) m = j ;
        if (m != i) {
            x=k[m];
            k[m]=k[i];
            k[i]=x;
        }
    }
}

void insert_sort(int k[], int n) {
    int i, j, x;
    for (i = 1 ; i < n ; i++) {
        x = k[i];
        j = i - 1;
        while (x < k[j] && j >= 0) {
            k[j+1] = k[j] ;
            j = j - 1;
        }
        k[j+1] = x ;
    }
}

void bubble_sort(int k[], int n) {
    int i, j, x;
    for (i = 0; i < n - 1 ; i++){
        for (j = n ; j > i ; j--){
            if ( k[j] < k[j-1] ){
                x = k[j];
                k[j] = k[j-1];
                k[j-1] = x; 
            }
        }
    }
}

void merge(int k[],int p,int q,int r){
    int l1=p, r1=q, l2=q+1, r2=r, index=p;
    int tempk[r+1];
    for(;(l1<=r1) && (l2<=r2);index++){
        if(k[l1]<k[l2]){
            tempk[index]=k[l1];
            l1++;
        }
        else{
            tempk[index]=k[l2];
            l2++;
        }
    }
    for(;l1<=r1;l1++, index++){
        tempk[index]=k[l1];
    }
    for(;l2<=r2;l2++, index++){
        tempk[index]=k[l2];
    }
    for(index=p; index<=r; index++){
        k[index]=tempk[index];
    }
}

void merge_sort(int k[], int p, int r){
    if(p<r){
        int q=(p+r)/2;
        merge_sort(k,p,q);
        merge_sort(k,q+1,r);
        merge(k,p,q,r);
    }
}

int right_partition(int k[], int p, int r){
    int pivot=k[r], x;
    int i=p-1;
    for(int j=p; j<r; j++){
        if(pivot>k[j]){
            i++;
            x=k[j];
            k[j]=k[i];
            k[i]=x;
        }
    }
    i++;
    x=k[r];
    k[r]=k[i];
    k[i]=x;
    return i;
}

void quick_sort(int k[], int p, int r){
    if(p<r){
        int q=right_partition(k, p, r);
        quick_sort(k,p,q-1);
        quick_sort(k,q+1,r);
    }
}

void max_heapify(int K[], int i, int n){
    int j=2*i; 
    if(j>n) return;
    if(j<n && K[j]<K[j+1]) j++;
    if(K[i]>K[j]) j=i;
    if(j!=i){
        int temp=K[i];
        K[i]=K[j];
        K[j]=temp;
        max_heapify(K,j,n);
    }
}

void min_heapify(int K[], int i, int n){
    int j=2*i;
    if(j>n) return;
    if(j<n && K[j]>K[j+1]) j++;
    if(K[i]<K[j]) j=i;
    if(j!=i){
        int temp=K[j];
        K[j]=K[i];
        K[i]=temp;
        min_heapify(K,j,n);
    }
}

void heap_sort(int A[], int n){
    for(int i=n/2;i>=1;i--){
        max_heapify(A, i, n);
    }
    for(int i=n;i>1;i--){
        int temp=A[1];
        A[1]=A[i];
        A[i]=temp;
        max_heapify(A,1,i-1);
    }
}

int main(){
    int a[8]={0, 5, 1, 7, 4, 2, 8, 6};
    heap_sort(a,7);
    for(int i=0;i<8;i++) printf("%d ",a[i]);
}