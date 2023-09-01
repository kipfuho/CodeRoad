#include<bits/stdc++.h>
#include<string>
#define FOR(i, l, r) for(int i = l; i <= r; i++)

using namespace std;

typedef struct _treenode{
    int data;
    struct _treenode *next;
    struct _treenode *child;
} Node;

typedef struct _forest{
    Node *center;
} Forest;

Node *Create_node(int k){
    Node *node = new Node;
    node->data = k;
    node->child =NULL;
    node->next = NULL;
    return node;
}

Forest *Create_forest(){
    Forest *f = new Forest;
    f->center = Create_node(-1);
    return f;
}

Node *find_node(Node *top, int v){
    if(top == NULL) return NULL;
    if(top->data == v) return top;
    Node *res = NULL;
    res = find_node(top->next, v);
    if(res == NULL) res = find_node(top->child, v);
    return res;
}

void MakeRoot(Forest *f, int u){
    Node *root = Create_node(u);
    Node *temp = f->center;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = root;
}

void Insert(Forest *f, int u, int v){
    Node *temp = f->center->next;
    if(temp == NULL) return ;
    Node *node;
    while(temp != NULL){
        node = find_node(temp, v);
        if(node != NULL) break ;
        temp = temp->next;
    }
    if(node == NULL) return ;
    if(node->child == NULL){
        node->child = Create_node(u);
        return ;
    }
    Node *tmp = node->child;
    while(tmp->next != NULL) tmp = tmp->next;
    tmp->next = Create_node(u);
}

void PreOrder(Node *node){
    if(node == NULL) return ;
    cout << node->data << " ";
    Node *temp = node->child;
    while(temp != NULL){
        PreOrder(temp);
        temp = temp->next;
    }
}

void PostOrder(Node *node){
    if(node == NULL) return ;
    Node *temp = node->child;
    while(temp != NULL){
        PostOrder(temp);
        temp = temp->next;
    }
    cout << node->data << " ";
}

void InOrder(Node *node){
    if(node == NULL) return ;
    if(node->child == NULL){
        cout << node->data << " ";
        return ;
    }
    Node *temp = node->child;
    InOrder(temp);
    cout << node->data << " ";
    temp = temp->next;
    while(temp != NULL){
        InOrder(temp);
        temp = temp->next;
    }
}

string str[3];

void split_string(string s){
    char *p = new char [s.size() + 1];
    strcpy(p, s.c_str());
    char *pch = strtok(p, " ");
    int i = 0;
    while(pch != 0){
        str[i++] = pch;
        pch = strtok(NULL, " ");
    }
}

int main(){
    Forest *f=Create_forest();
    while(true){
        string s;
        getline(cin, s);
        if(s == "*") break;
        split_string(s);
        if(str[0] == "MakeRoot"){
            MakeRoot(f, stoi(str[1]));
        }
        if(str[0] == "Insert"){
            Insert(f, stoi(str[1]), stoi(str[2]));
        }
        if(str[0] == "PreOrder"){
            Node *temp = f->center->next;
            while(temp != NULL){
                PreOrder(temp);
                cout << endl;
                temp = temp->next;
            }
        }
        if(str[0] == "PostOrder"){
            Node *temp = f->center->next;
            while(temp != NULL){
                PostOrder(temp);
                cout << endl;
                temp = temp->next;
            }
        }
        if(str[0] == "InOrder"){
            Node *temp = f->center->next;
            while(temp != NULL){
                InOrder(temp);
                cout << endl;
                temp = temp->next;
            }
        }
    }
}