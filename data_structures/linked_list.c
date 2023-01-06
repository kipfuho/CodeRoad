#include<stdio.h>
#include<stdlib.h>
typedef struct Node Node;
typedef struct Llist llist;

struct Node{
    int x;
    int y;
    Node *next;
};

Node *Create(int x, int y){
    Node *temp=malloc(sizeof(Node));
    temp->x=x;
    temp->y=y;
    return temp;
}

void Create_List(Node *head, int n){
    Node *temp=head;
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d %d", x, y);
        temp->next=Create(x,y);
        temp=temp->next;
    }
}

void insert(Node *head, Node *source){
    Node *temp=head, *prev=NULL;
    if(temp==NULL) return;
    while(1){
        if(temp->y==source->y){
            temp->x+=source->x;
            return;
        }
        if(source->y<temp->y){
            if(prev==NULL){
                source->next=temp;
            }
            source->next=temp->next;
            temp->next=source;
            return;
        }
        if(temp->next==NULL){
            temp->next=source;
            source->next=NULL;
            return;
        }
        prev=temp;
        temp=temp->next;
    }
}

void merge(Node *head1, Node *head2){
    Node *temp=head2;
    while(temp!=NULL){
        insert(head1, temp);
        temp=temp->next;
    }
}

void display(Node *head){

}