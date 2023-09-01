#include<bits/stdc++.h>
#include<vector>
#include<string>
#define FOR(i, l, r) for(int i = l;i <= r; i++)

using namespace std;

typedef struct _node{
    int data;
    struct _node *next;
} Node;

typedef struct _linkedlist{
    Node *head;
} LinkedList;

Node *Create_node(int k){
    Node *node = new Node;
    node->data = k;
    node->next = NULL;
    return node;
}

LinkedList *Create_list(){
    LinkedList *l = new LinkedList;
    l->head = Create_node(-1);
    return l;
}

Node *find_node(LinkedList *l, int u){
    Node *temp = l->head;
    while(temp->next != NULL){
        if(temp->next->data == u) return temp;
        temp = temp->next;
    }
    return NULL;
}

void addlast(LinkedList *l, int k){
    Node *temp = l->head;
    while(temp->next != NULL){
        if(temp->data == k) return ;
        temp = temp->next;
    }
    if(temp->data == k) return ;
    temp->next = Create_node(k);
}

void addfirst(LinkedList *l, int k){
    Node *node = find_node(l, k);
    if(node != NULL) return ;
    Node *temp = Create_node(k);
    temp->next = l->head->next;
    l->head->next = temp;
}

void addafter(LinkedList *l, int u, int v){
    Node *node2 = find_node(l, u);
    if(node2 != NULL) return ;
    Node *node1 = find_node(l, v);
    if(node1 == NULL) return ;
    node1 = node1->next;
    Node *temp = Create_node(u);
    temp->next = node1->next;
    node1->next = temp;
}

void addbefore(LinkedList *l, int u, int v){
    Node *node2 = find_node(l, u);
    if(node2 != NULL) return ;
    Node *node1 = find_node(l, v);
    if(node1 == NULL) return ;
    Node *temp = Create_node(u);
    temp->next = node1->next;
    node1->next = temp;
}

void remove(LinkedList *l, int k){
    Node *temp = find_node(l, k);
    if(temp == NULL) return ;
    Node *node = temp->next;
    temp->next = node->next;
    free(node);
}

void reverse(LinkedList *l){
    Node *b = l->head->next;
    if(b == NULL || b->next == NULL) return ;
    Node *a = NULL, *c = b->next;
    while(c != NULL){
        b->next = a;
        a = b;
        b = c;
        c = c->next;
    }
    b->next = a;
    l->head->next = b;
}

void display_list(LinkedList *l){
    Node *temp = l->head->next;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
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
    LinkedList *l = Create_list();
    int n; cin >> n;
    FOR(i, 1, n){
        int k; cin >> k;
        addlast(l, k);
    }
    while(true){
        fflush(stdin);
        string s;
        getline(cin, s);
        if(s == "#") break;
        split_string(s);
        if(str[0] == "addlast"){
            addlast(l, stoi(str[1]));
        }
        if(str[0] == "addfirst"){
            addfirst(l, stoi(str[1]));
        }
        if(str[0] == "addafter"){
            addafter(l, stoi(str[1]), stoi(str[2]));
        }
        if(str[0] == "addbefore"){
            addbefore(l, stoi(str[1]), stoi(str[2]));
        }
        if(str[0] == "remove"){
            remove(l, stoi(str[1]));
        }
        if(str[0] == "reverse"){
            reverse(l);
        }
    }
    display_list(l);
}