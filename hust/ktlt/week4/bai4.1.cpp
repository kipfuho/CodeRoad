// Nguyen Dinh Ut Biu 20215317
// Bài 4.1: Ðao nguoc mot danh sách liên ket don

#include <iostream> 
using namespace std;
struct Node { 
    int data; 
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// push a new element to the beginning of the list
Node* prepend(Node* head, int data) {
    Node *temp = new Node(data);
    temp->next = head;
    return temp;
}

// print the list content on a line
void print(Node* head) {
    while(head != NULL) {
    	cout << head->data << " ";
    	head = head->next;
	}
	cout << endl;
}

// return the new head of the reversed list
Node* reverse(Node* head) {
	// 3 pointer to different positions of the linked list
    Node *prev = NULL, *curr = head, *next = head->next;
    // changing pointer *next of curr and advance 3 pointers
    while(next != NULL){
    	curr->next = prev;
    	prev = curr;
    	curr = next;
    	next = next->next;
	}
	// change the last position and return it
	curr->next = prev;
	return curr;
}
  
int main() {
    int n, u;
    cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; ++i){
        cin >> u;
        head = prepend(head, u);
    } 
    
    cout << "Original list: ";
    print(head);

    head = reverse(head);
    
    cout << "Reversed list: ";
    print(head);

    return 0; 
}
