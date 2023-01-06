#include<stdio.h>
#include<stdlib.h>
#include "stdbool.h"

//short keyword, constant
#define ll long long
#define M 111317 //8645179 ---- hashtable size

//global invariable
int x[9][9]; //sudoku matrix
int counter=0;

typedef struct _polynode{
	int coef;
	int pow;
	struct _polynode *next;
} PolyNode;

typedef struct _hashnode{
	int data;
	int key;
	struct _hashnode *next;
} Hashnode;

typedef struct _hashtable{
	Hashnode **node;
} Hashtable;

//dem so phan tu X xuat hien trong day A
int logCount(int A[], int N, int X){
	int l1=1, r1=N, l2=1, r2=N;
	while(r1-l1>1){
		int mid=(l1+r1)/2;
		if(A[mid]>X){
			l1=mid;
		}
		else{
			r1=mid;
		}
	}
	while(r2-l2>1){
		int mid=(l2+r2)/2;
		if(A[mid]<X){
			r2=mid;
		}
		else{
			l2=mid;
		}
	}
    printf("%d %d %d %d\n",l1,r1,l2,r2);
	return l2-r1+1+(l1==1)+(r2==N);
}

int logcount2(int A[], int l, int r, int X){
	if(A[l]==X && A[r]==X) return r-l+1;
	if(l<r){
		int mid=(l+r)/2;
		if(A[mid]>X) return logcount2(A,mid+1,r,X);
		else if(A[mid]<X) return logcount2(A,l,mid-1,X);
		else return 1+logcount2(A,l,mid-1,X)+logcount2(A,mid+1,r,X);
	}
	return 0;
}


//sort functions
void merge(int A[], int l, int m, int r){
	int K[r-l+1], i=0, j=l, k=m+1, n=r-l+1;
	while(i<n){
		if(A[j]<A[k] && j<=m && k<=r){
			K[i++]=A[j++];
		}
		else if(k<=r){
			K[i++]=A[k++];
		}
		else{
			K[i++]=A[j++];
		}
	}
	j=0;
	for(i=l;i<=r;i++){
		A[i]=K[j++];
	}
}

void merge_sort(int A[], int l, int r){
	if(r-l<1) return;
	int mid=(l+r)/2;
	merge_sort(A,l,mid);
	merge_sort(A,mid+1,r);
	merge(A,l,mid,r);
}

void insertion_sort(int A[], int l, int r){
	for(int i=l+1;i<=r;i++){
		int x=A[i], j=i-1;
		while(x<A[j] && j>=0){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=x;
	}
}

int partition(int A[], int l, int r){
	int pivot=A[r];
	int i=l-1,j;
	for(j=l;j<r;j++){
		if(pivot>A[j]){
			i++;
			int t=A[j];
			A[j]=A[i];
			A[i]=t;
		}
	}
	i++;
	j=A[i];
	A[i]=pivot;
	A[r]=j;
	return i;
}

void quick_sort(int A[], int l, int r){
	if(l<r){
		int pi=partition(A,l,r);
		if(pi-l<10 && r-pi<9){
			insertion_sort(A,l,pi-1);
			insertion_sort(A,pi+1,r);
			return;
		}
		if(pi-l<10){
			insertion_sort(A,l,pi-1);
			quick_sort(A,pi+1,r);
			return;
		}
		if(r-pi<9){
			quick_sort(A,l,pi-1);
			insertion_sort(A,pi+1,r);
			return;
		}
		quick_sort(A,l,pi-1);
		quick_sort(A,pi+1,r);
	}
}

void max_heapify(int A[], int i, int n){
	int j=2*i;
	if(j>n) return;
	int max=A[j];
	if(j<n && A[j+1]>A[j]){
		max=A[j+1];
		j++;
	}
	if(A[i]>max) j=i;
	if(j==i) return;
	int t=A[j];
	A[j]=A[i];
	A[i]=t;
	max_heapify(A,j,n);
}

void heap_sort(int A[], int l, int r){
	int n=r-l+1, m=r;
	for(int i=n/2;i>0;i--){
		max_heapify(A,i,n);
	}
	for(int i=1;i<r;i++){
		int t=A[1];
		A[1]=A[m];
		A[m--]=t;
		max_heapify(A,1,m);
	}
}

//polynomial functions
//Q(x)=2*x*P(x)+3x-1
PolyNode *thaydoidathuc(PolyNode *p){
	PolyNode *a, *b, *head;
	head=p; int mode=0;
	a=malloc(sizeof(PolyNode));
	b=malloc(sizeof(PolyNode));
	a->coef=-1;
	a->pow=0;
	a->next=b;
	b->coef=3;
	b->pow=1;
	while(head!=NULL){
		head->coef*=2;
		head->pow++;
		if(head->pow==1){
			b->coef+=head->coef;
			b->next=head->next;
			mode=1;
		}
		head=head->next;
	}
	if(mode==0){
		b->next=p;
	}
	return a;
}

void display_polynode(PolyNode *p){
	PolyNode *temp=p;
	while(temp!=NULL){
		printf("%dx^%d ",temp->coef, temp->pow);
		temp=temp->next;
	}
	printf("\n");
}

PolyNode *congdathuc(PolyNode *p1, PolyNode *p2){
	if(p1==NULL && p2==NULL) return NULL;
	if(p1==NULL) return p2;
	if(p2==NULL) return p1;
	PolyNode *p=p1, *q=p2, *node=malloc(sizeof(PolyNode)), *temp, *res=NULL;
	node->next=NULL;
	temp=node;
	res=temp;
	while(p!=NULL && q!=NULL){
		temp=node; //thiet lap lai nut cuoi
		int pow1=p->pow, pow2=q->pow, coef1=p->coef, coef2=q->coef;
		if(pow1>pow2){
			temp->coef=coef2;
			temp->pow=pow2;
			q=q->next;
		}
		else if(pow1<pow2){
			temp->coef=coef1;
			temp->pow=pow1;
			p=p->next;
		}
		else{
			temp->coef=coef1+coef2;
			temp->pow=pow1;
			p=p->next;
			q=q->next;
		}

		if(p==NULL && q==NULL) return res; //ngung thuat toan, neu khong node cuoi se khong duoc dinh nghia

		node=malloc(sizeof(PolyNode));
		node->next=NULL;
		temp->next=node;
	}

	if(p!=NULL) temp->next=p; // k the gan node cho p hoac q duoc vi node da duoc alloc memory
	if(q!=NULL) temp->next=q;

	return res;
}

//sudoku backtracking
void printSolution_sudoku(){
	printf("\n--------------------------\n");
	for(int i = 0; i < 9; i++){
		printf("\n");
		for(int j = 0; j < 9; j++)
			printf("%d ",x[i][j]);
	}
	counter++;
	if(counter==5)
		exit(1);
}

bool check_sudoku(int v, int r, int c){
	for(int i = 0; i <= r-1; i++)
		if(x[i][c] == v) return false;
	for(int j = 0; j <= c-1; j++)
		if(x[r][j] == v) return false;
		
	int I = r/3;
	int J = c/3;
	int i = r - 3*I;
	int j = c - 3*J;
	for(int i1 = 0; i1 <= i-1; i1++)
		for(int j1 = 0; j1 <= 2; j1++)
			if(x[3*I+i1][3*J+j1] == v)
				return false;
	for(int j1 = 0; j1 <= j-1; j1++)
		if(x[3*I+i][3*J+j1] == v)
			return false;
			
	return true;
}

void TRY_sudoku(int r, int c){
	for(int v = 1; v <= 9; v++){
		if(check_sudoku(v,r,c)){
			x[r][c] = v;
			if(r == 8 && c == 8){
				printSolution_sudoku();
			}else{
				if(c == 8) TRY_sudoku(r+1,0);
				else TRY_sudoku(r,c+1);
			}
		}
	}
}

//hash table sections
int hash_function(int k){
	return k%M;
}

Hashtable *create_hashtable(){
	Hashtable *t=malloc(sizeof(Hashtable));
	t->node=malloc(M*sizeof(Hashnode));
	for(int i=0; i<M; i++) t->node[i]=NULL;
}

Hashnode *create_hashnode(int data){
	Hashnode *temp=malloc(sizeof(Hashnode));
	temp->data=data;
	temp->key=hash_function(data);
	temp->next=NULL;
	return temp;
}

void insert_hashtable(Hashtable *t, Hashnode *node){
	if(node==NULL) return;
	int key=node->key;
	Hashnode *temp=t->node[key];
	if(temp==NULL) temp=node;
	else{
		while(temp->next!=NULL) temp=temp->next;
		temp->next=node;
	}
}

void delete_hashtable(){
	
}
/*
int main(){
	PolyNode *a, *b, *c, *d, *e, *f, *g;
	a=malloc(sizeof(PolyNode));
	b=malloc(sizeof(PolyNode));
	c=malloc(sizeof(PolyNode));
	d=malloc(sizeof(PolyNode));
	e=malloc(sizeof(PolyNode));
	f=malloc(sizeof(PolyNode));
	a->next=b; b->next=c; c->next=NULL; d->next=e; e->next=f; f->next=NULL;
	a->coef=2; b->coef=6; c->coef=3; d->coef=4; e->coef=7; f->coef=11;
	a->pow=0; b->pow=1; c->pow=2, d->pow=3, e->pow=5, f->pow=6;
	g=congdathuc(a,d);
	display_polynode(a);
	display_polynode(d);
	display_polynode(g);
}*/

int main()
{
    int a=2, *b=&a, **c=&b;
	printf("%d %d %d",a , *b, **c);
}