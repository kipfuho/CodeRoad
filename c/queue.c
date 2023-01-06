#include<stdio.h>
#include<stdlib.h>

typedef struct _qnode{
    int item;
    struct _qnode *next;
} Node;

typedef struct _linkedlist{
    Node *head;
    Node *tail;
    int size;
} LinkedList;

typedef struct _queue{
    LinkedList ll;
} Queue;

void enqueue(Queue *q, int item){
    Node *temp=malloc(sizeof(Node));
    temp->item=item;
    temp->next=NULL;
    if(q->ll.head==NULL){
        q->ll.head=q->ll.tail=temp;
        return;
    }
    q->ll.tail->next=temp;
    q->ll.tail=temp;
}

int dequeue(Queue *q){
    Node *temp=q->ll.head;
    q->ll.head=q->ll.head->next;
    int k=temp->item;
    free(temp);
    return k;
}

int isEmptyQueue(Queue *q){
    return (q->ll.head==NULL);
}