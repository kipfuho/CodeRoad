//binary search tree
#include<stdio.h>
#include<stdlib.h>

typedef struct _btnode {
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

typedef struct _btnode2 {
    char item;
    struct _btnode2 *left;
    struct _btnode2 *right;
} BTNode2;

void TreeTraversal_PreOrder(BTNode *cur) {
    if(cur==NULL) return;
    printf("%d ",cur->item);
    TreeTraversal_PreOrder(cur->left);
    TreeTraversal_PreOrder(cur->right);
}

void TreeTraversal_InOrder(BTNode *cur) {
    if(cur==NULL) return;
    TreeTraversal_InOrder(cur->left);
    printf("%d ",cur->item);
    TreeTraversal_InOrder(cur->right);
}

void TreeTraversal_InOrder2(BTNode2 *cur) {
    if(cur==NULL) return;
    TreeTraversal_InOrder2(cur->left);
    printf("%c", cur->item);
    TreeTraversal_InOrder2(cur->right);
}

void TreeTraversal_PostOrder(BTNode *cur) {
    if(cur==NULL) return;
    TreeTraversal_PostOrder(cur->left);
    TreeTraversal_PostOrder(cur->right);
    printf("%d ",cur->item);
}

BTNode2* BSTT(BTNode2 *cur, char c) {
    if (cur == NULL)
        return NULL;
    if (c==cur->item) 
        return cur;
    if (c < cur->item)
        return BSTT(cur->left, c);
    else
        return BSTT(cur->right, c);
}

BTNode2* BSTT2(BTNode2 *cur, char c) {
    if (c==cur->item) 
        return NULL;
    if (c < cur->item) {
        if (cur->left == NULL )
            return cur;
        return BSTT2(cur->left, c);
    }
    else {
        if (cur->right == NULL)
            return cur;
        return BSTT2(cur->right, c);
    }
}

BTNode *mostleftNode(BTNode *cur){
    if(cur->left==NULL) return cur;
    return mostleftNode(cur->left);
}

BTNode *removeBST(BTNode *cur, int num) {
    if(cur == NULL) return cur;
    if(num < cur->item){
        cur->left=removeBST(cur->left, num);
    }
    else if(num > cur->item){
        cur->right=removeBST(cur->right, num);
    }
    else{
        if(cur->left == NULL){
            BTNode *temp = cur->right;
            free(cur);
            return temp;
        }
        else if(cur->right == NULL){
            BTNode *temp = cur->left;
            free(cur);
            return temp;
        }
        else{
            BTNode *temp = mostleftNode(cur->right);
            cur->item = temp->item;
            cur->right=removeBST(cur->right, temp->item);
        }
    }
    return cur;
}

int countNode(BTNode *cur){
    if(cur == NULL) return 0;
    if(cur->left == NULL || cur->right == NULL) return 1;
    return countNode(cur->left) + countNode(cur->right);
}

void findgrandchildren(BTNode *cur, int c, int k){
    if(cur == NULL) return;
    if(c == k){
        printf("%d", cur->item);
        return;
    }
    findgrandchildren(cur->left, c+1, k);
    findgrandchildren(cur->right, c+1, k);
}

int heightTree(BTNode *cur){
    if(cur == NULL) return 0;
    if(cur->left==NULL && cur->right==NULL) return 1;
    int x=heightTree(cur->left);
    int y=heightTree(cur->right);
    return 1 + (x>y?x:y);
}

int main(void) {
    int item1 = 2, item2 = 1, item3 = 3;
    BTNode *btnode1, *btnode2, *btnode3;

    btnode1 = malloc(sizeof(BTNode));
    btnode2 = malloc(sizeof(BTNode));
    btnode3 = malloc(sizeof(BTNode));

    btnode1->item = item1;
    btnode2->item = item2;
    btnode3->item = item3;

    btnode2->left = NULL;
    btnode2->right = NULL;

    btnode3->left = NULL;
    btnode3->right = NULL;

    btnode1->left = btnode2 ;
    btnode1->right = btnode3 ;

    //printf("\nDuyet cay theo thu tu truoc: ");
    //TreeTraversal_PreOrder( &btnode1 );

    //printf("\nDuyet cay theo thu tu giua: ");
    //TreeTraversal_InOrder( &btnode1 );

    //printf("\nDuyet cay theo thu tu sau: ");
    //TreeTraversal_PostOrder( &btnode1  );

    //TreeTraversal_PreOrder( &btnode1 );
    //removeBST(btnode1, 2);
    //TreeTraversal_PreOrder( &btnode1 );

    //findgrandchildren(btnode1, 1, 0);
    //printf("%d",heightTree(btnode1));
}

/*main2
int main(void) {
    BTNode2 *btnodeA, *btnodeB, *btnodeC, *btnodeD, *btnodeE, *btnodeF, *btnodeG, *btnodeH, *btnodeI, *btnodeJ, *btnodeK, *btnodeL, *btnodeM;
    btnodeA = malloc(sizeof(BTNode2));
    btnodeB = malloc(sizeof(BTNode2));
    btnodeC = malloc(sizeof(BTNode2));
    btnodeD = malloc(sizeof(BTNode2));
    btnodeE = malloc(sizeof(BTNode2));
    btnodeF = malloc(sizeof(BTNode2));
    btnodeG = malloc(sizeof(BTNode2));
    btnodeH = malloc(sizeof(BTNode2));
    btnodeI = malloc(sizeof(BTNode2));
    btnodeJ = malloc(sizeof(BTNode2));
    btnodeK = malloc(sizeof(BTNode2));
    btnodeL = malloc(sizeof(BTNode2));
    btnodeM = malloc(sizeof(BTNode2));

    btnodeA->item='A';
    btnodeB->item='B';
    btnodeC->item='C';
    btnodeD->item='D';
    btnodeE->item='E';
    btnodeF->item='F';
    btnodeG->item='G';
    btnodeH->item='H';
    btnodeI->item='I';
    btnodeJ->item='J';
    btnodeK->item='K';
    btnodeL->item='L';
    btnodeM->item='M';

    btnodeA->left=NULL;
    btnodeA->right=NULL;

    btnodeB->left=btnodeA;
    btnodeB->right=btnodeC;

    btnodeC->left=NULL;
    btnodeC->right=btnodeD;


    btnodeD->left=NULL;
    btnodeD->right=NULL;

    btnodeE->left=btnodeB;
    btnodeE->right=btnodeF;

    btnodeF->left=NULL;
    btnodeF->right=btnodeG;

    btnodeG->left=NULL;
    btnodeG->right=NULL;

    btnodeH->left=btnodeE;
    btnodeH->right=btnodeL;

    btnodeI->left=NULL;
    btnodeI->right=NULL;

    btnodeJ->left=btnodeI;
    btnodeJ->right=btnodeK;

    btnodeK->left=NULL;
    btnodeK->right=NULL;

    btnodeL->left=btnodeJ;
    btnodeL->right=btnodeM;

    btnodeM->left=NULL;
    btnodeM->right=NULL;

    printf("\n\nCay nhi phan tim kiem truoc khi chen:\n ");
    TreeTraversal_InOrder2( btnodeH );
    
    // Insert
    char q = 'Q';
    BTNode2 *posNode = BSTT2( btnodeH, q );

    BTNode2 *btNewNode = malloc( sizeof(BTNode2) );
    btNewNode->item = q;
    btNewNode->left = NULL;
    btNewNode->right = NULL;
    if (posNode == NULL) {
        printf("Phan tu da ton tai");
        return 0;
    }

    if (q < posNode->item)
        posNode->left=btNewNode;
    else 
        posNode->right=btNewNode;

    printf("\n\nCay nhi phan tim kiem sau khi chen:\n ");
    TreeTraversal_InOrder2(btnodeH);
}*/

