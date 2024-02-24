/*
Description
Given a BST initialized by NULL. Perform a sequence of operations on a BST including:
insert k: insert a key k into the BST (do not insert if the key k exists)
Input
•Each line contains command under the form: “insert k”
•The input is terminated by a line containing #
Output
•Write the sequence of keys of nodes visited by the pre-order traversal (separated by a SPACE character)
Example
Input
insert 20
insert 10
insert 26
insert 7
insert 15
insert 23
insert 30
insert 3
insert 8
#
Output
20 10 7 3 8 15 26 23 30
*/

#include<bits/stdc++.h>

using namespace std;

struct BTNode {
    bool isNull;
    int item;
    vector<BTNode> child;
    BTNode(){
        isNull = true;
    }
    BTNode(int val){
        isNull = false;
        item = val;
        child.push_back(BTNode());
        child.push_back(BTNode());
    }
};

BTNode nNode = BTNode();

void TreeTraversal_PreOrder(BTNode& cur) {
    cout << cur.item << " ";
    if(!cur.child[0].isNull) TreeTraversal_PreOrder(cur.child[0]);
    if(!cur.child[1].isNull) TreeTraversal_PreOrder(cur.child[1]);
    return;
}

void TreeTraversal_InOrder(BTNode& cur) {
    if(!cur.child[0].isNull) TreeTraversal_InOrder(cur.child[0]);
    cout << cur.item << " ";
    if(!cur.child[1].isNull) TreeTraversal_InOrder(cur.child[1]);
    return;
}

void TreeTraversal_PostOrder(BTNode& cur) {
    if(!cur.child[0].isNull) TreeTraversal_PostOrder(cur.child[0]);
    if(!cur.child[1].isNull) TreeTraversal_PostOrder(cur.child[1]);
    cout << cur.item << " ";
    return;
}

BTNode& TreeFindNode(BTNode& cur, BTNode& nullNode, int val){
    if(cur.item > val){
        if(cur.child[0].isNull) return cur;
        else return TreeFindNode(cur.child[0], nullNode, val);
    }
    else if(cur.item < val){
        if(cur.child[1].isNull) return cur;
        else return TreeFindNode(cur.child[1], nullNode, val);
    }
    else return nullNode;
}

int TreeInsert(BTNode& root, int val){
    BTNode& insertNode = TreeFindNode(root, nNode, val);
    if(!insertNode.isNull){
        if(val < insertNode.item){
            insertNode.child[0] = BTNode(val);
        }
        else{
            insertNode.child[1] = BTNode(val);
        }
        return 1;
    }
    return 0;
}

int main(){
    BTNode root;
    string s;
    while(cin >> s){
        if(s == "#") break;
        else if(s == "insert"){
            int temp; cin >> temp;
            if(!root.isNull) TreeInsert(root, temp);
            else root = BTNode(temp);
        }
        else continue;
    }


    TreeTraversal_PreOrder(root);
    cout << endl;

    return 0;
}