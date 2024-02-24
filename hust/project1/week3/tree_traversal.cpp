/*
Description
Mỗi nút trên cây có trường id (identifier) là một số nguyên (id của các nút trên cây đôi một khác nhau)
Thực hiện 1 chuỗi các hành động sau đây bao gồm các thao tác liên quan đến xây dựng cây và duyệt cây
· MakeRoot u: Tạo ra nút gốc u của cây
· Insert u v: tạo mới 1 nút u và chèn vào cuối danh sách nút con của nút v (nếu nút có id bằng v không tồn tại hoặc nút có id bằng u đã tồn tại thì không chèn thêm mới)
· PreOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự trước
· InOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự giữa
· PostOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự sau
Dữ liệu: bao gồm các dòng, mỗi dòng là 1 trong số các hành động được mô tả ở trên, dòng cuối dùng là * (đánh dấu sự kết thúc của dữ liệu).
Kết quả: ghi ra trên mỗi dòng, thứ tự các nút được thăm trong phép duyệt theo thứ tự trước, giữa, sau của các hành động PreOrder, InOrder, PostOrder tương ứng đọc được từ dữ liệu đầu vào
Ví dụ
Dữ liệu
MakeRoot 10
Insert 11 10
Insert 1 10
Insert 3 10
InOrder
Insert 5 11
Insert 4 11
Insert 8 3
PreOrder
Insert 2 3
Insert 7 3
Insert 6 4
Insert 9 4
InOrder
PostOrder
*
Kết quả
11 10 1 3
10 11 5 4 1 3 8
5 11 6 4 9 10 1 8 3 2 7
5 6 9 4 11 1 8 2 7 3 10
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
    }
};

BTNode nNode = BTNode();

void TreeTraversal_PreOrder(BTNode& cur) {
    cout << cur.item << " ";
    for(auto& node:cur.child) TreeTraversal_PreOrder(node);
    return;
}

void TreeTraversal_InOrder(BTNode& cur) {
    if(cur.child.size() > 0) TreeTraversal_InOrder(cur.child[0]);
    cout << cur.item << " ";
    for(int i = 1; i < cur.child.size(); i++ ) TreeTraversal_InOrder(cur.child[i]);
    return;
}

void TreeTraversal_PostOrder(BTNode& cur) {
    for(auto& node:cur.child) TreeTraversal_PostOrder(node);
    cout << cur.item << " ";
    return;
}

BTNode& TreeFindNode(BTNode& cur, BTNode& nullNode, int val){
    if(cur.item == val) return cur;
    else{
        for(auto& node:cur.child){
            BTNode& temp = TreeFindNode(node, nNode, val);
            if(!temp.isNull) return temp;
        }
    }
    return nullNode;
}

int TreeInsert(BTNode& root, int atItem, int val){
    BTNode& insertNode = TreeFindNode(root, nNode, atItem);
    if(!insertNode.isNull){
        if(TreeFindNode(root, nNode, val).isNull){
            insertNode.child.push_back(BTNode(val));
            return 1;
        }
    }
    return 0;
}

int main(){
    BTNode root;
    string s;
    while(cin >> s){
        if(s == "#") break;
        else if(s == "MakeRoot"){
            int temp; cin >> temp;
            root = BTNode(temp);
        }
        else if(s == "Insert"){
            int temp1, temp2; cin >> temp1 >> temp2;
            if(!root.isNull) TreeInsert(root, temp2, temp1);
        }
        else if(s == "PreOrder"){
            TreeTraversal_PreOrder(root);
            cout << endl;
        }
        else if(s == "InOrder"){
            TreeTraversal_InOrder(root);
            cout << endl;
        }
        else if(s == "PostOrder"){
            TreeTraversal_PostOrder(root);
            cout << endl;
        }
        else continue;
    }
    
    return 0;
}