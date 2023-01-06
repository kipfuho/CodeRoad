#include<stdio.h>
#include<stdlib.h>

typedef struct _avlnode{
    int item;
    int height;
    int balance;
    struct _avlnode *left;
    struct _avlnode *right;
} Node;

typedef struct _avltree{
    Node *root;
} AVL;

Node *create_node(int item){
    Node *temp=malloc(sizeof(Node));
    temp->item=item;
    temp->height=1;
    temp->balance=0;
    temp->left=NULL;
    temp->right=NULL;
}

AVL *create_tree(){
    AVL *temp=malloc(sizeof(AVL));
    temp->root=NULL;
    return temp;
}

int max(int x, int y){
    return x>y?x:y;
}

int min(int x, int y){
    return x<y?x:y;
}

void PreProcess(Node *cur){
    if(cur==NULL || (cur->left==NULL && cur->right==NULL)) return;
    PreProcess(cur->left);
    PreProcess(cur->right);
    Node *left=cur->left, *right=cur->right;
    if(left!=NULL && right!=NULL){
        cur->height=1+max(left->height, right->height);
        cur->balance=left->height-right->height;
    }
    else if(left==NULL){
        cur->height=1+right->height;
        cur->balance=-right->height;
    }
    else{
        cur->height=1+left->height;
        cur->balance=left->height;
    }
}

int check_avltree(Node *cur){
    if(cur==NULL) return 1;
    if(cur->balance>1 || cur->balance<-1) return 0;
    return check_avltree(cur->left) && check_avltree(cur->right);
}

int main(){
    printf("%d", 1&&0);
}