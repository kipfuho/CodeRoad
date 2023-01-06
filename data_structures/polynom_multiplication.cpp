//polynomial multiplication
//such as h(x)=f(x)*g(x)
//polynom: a1+a2.x+a3.x**2+....+an.x**n+...


#include<bits/stdc++.h>

using namespace std;

struct Node{
	int coeff;
	int pow;
	int r;
	Node* next;
};

Node* Create(int coeff, int pow, int r){
	Node* node=new Node;
	node->coeff=coeff;
	node->pow=pow;
	node->r=r;
	node->next=NULL;
}

class llist_polym
{	
	public:

	Node* head;
	Node* tail;

	llist_polym(){
		head=NULL;
		tail=NULL;
	}

	void Add(Node* node){
		if(head==NULL){
			head=tail=node;
		}
		else{
			tail->next=node;
			tail=node;
		}
	}

	llist_polym operator* (llist_polym const &x){
		Node* temp1=this->head;
		while(temp1){
			Node* temp2=x.head;
			while(!temp2->next){
				int k=temp1->pow+temp2->pow;
				//undefined, not too efficient??
			}
			temp1=temp1->next;
		}
		Node* temp1=this->head;
		while(temp1){
			temp1->coeff=temp1->coeff+temp1->r;
			temp1->r=0;
			temp1=temp1->next;
		}
	}
};
