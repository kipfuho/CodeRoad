//#pragma once

#include<bits/stdc++.h>
#define ll long long
using namespace std;

//Node
struct Node{
    int value; //int
    Node* next;
};

Node* Create_node(int i){
    Node* node = new Node;
    node->value = i;
    node->next = NULL;
    return node;
}

//Linked List
struct LinkedList{
    Node* head;
    Node* tail;
};

//function
void list_creation(LinkedList& l){
    l.head = NULL;
    l.tail = NULL;
}

void addfirst(LinkedList& l, int u){
    Node *node=Create_node(u);
    if(l.head == NULL){
        l.head = node;
        l.tail = node;
    }
    else{
        node->next = l.head;
        l.head = node;
    }
}

void addlast(LinkedList& l, int u){
    Node *node=Create_node(u);
    if(l.head == NULL){
        l.head = node;
        l.tail = node;
    }
    else{
        l.tail->next=node;
        l.tail = node;
    }
}

void addafter(LinkedList& l, int u, int v){
    int mode=0;
    Node *temp=l.head, *node;
    while(temp!=NULL){
        if(temp->value==u) mode++;
        if(temp->value==v) mode+=2;
        temp=temp->next;
    }
    if(mode!=3) return;

}

void printList(LinkedList& l){
    if(l.head != NULL){
        Node* node = l.head;
        while(node != NULL){
            cout<<node->value;
            node = node->next;
        }
    }
}