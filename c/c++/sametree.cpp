#include<bits/stdc++.h>

bool result;
void order(struct TreeNode *p,struct TreeNode *q){
	if(result==false) return;
	if(p==NULL && q==NULL){
		return;
	}
	if(p==NULL || q==NULL){
		result=false;
		return;
	}
	if(p->val!=q->val){
		result=false;
		return;
	}
	else{
		order(p->left,q->left);
		order(p->right,q->right);
		return;
	}
}

bool isSameTree(struct TreeNode *p,struct TreeNode *q){
	result=true;
	order(p,q);
	return result;
}