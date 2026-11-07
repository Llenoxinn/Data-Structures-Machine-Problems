#include <iostream>
#include <queue>

using namespace std;

class node{
public:
	int item;
	node *left, *right, *parent;
	node(int x){
		item = x;
		left = right = parent = NULL;
	}
};

void preOrder(node *r){
	if(r!=NULL){
		cout<<r->item<<" "; 
		preOrder(r->left); 
		preOrder(r->right);
	}
}

void inOrder(node *r){
	if(r!=NULL){
		 
		inOrder(r->left); 
		cout<<r->item<<" ";
		inOrder(r->right);
	}
}

void postOrder(node *r){
	if(r!=NULL){
		postOrder(r->left);
		postOrder(r->right); 
		cout<<r->item<<" ";
	}
}

void levelOrder(node *r){
	if(r!=NULL){
		queue<node*> q;
		q.push(r);
		do{
			node *d = q.front();
			q.pop();
			cout<<d->item<<" ";
			if(d->left!=NULL)
				q.push(d->left);
			if(d->right!=NULL)
				q.push(d->right);
		}while(!q.empty());
		cout<<endl;
	}

}
/*
swap(int,int)
swap(x,y);
swap(&x,&y);
swap(int*,int*)
*/
void insert(node **r, int x){
	node *n = new node(x);
	if(*r == NULL)
		*r = n;
	else{
		node *curr = *r, *prev;
		while(curr!=NULL){
			prev = curr;
			if(x < curr->item)
				curr = curr->left;
			else
				curr = curr->right;
		}
		if(x < prev->item)
			prev->left = n;
		else
			prev->right = n;
		n->parent = prev;
	}
}

void rinsert(node **r, int x){
	if(*r == NULL)
		*r = new node(x);
	else{
		if(x < (*r)->item)
			rinsert(&((*r)->left),x);
		else
			rinsert(&((*r)->right),x);
	}
}

int count(node *n){
	if(n==NULL)
		return 0;
	else
		return 1 + count(n->left) + count(n->right);
}

bool search(node *r, int x){
	while(r!=NULL){
		if(x == r->item)
			return true;
		if(x < r->item)
			r = r->left;
		else
			r = r->right;
	}
	return false;
}

bool rsearch(node *r, int x){
	if(r==NULL)
		return false;
	if(x==r->item)
		return true;
	if(x<r->item)
		return rsearch(r->left,x);
	else
		return rsearch(r->right,x);
}

int minimum(node *r){
	if(r!=NULL){
		while(r->left!=NULL)
			r = r->left;
		return r->item;
	}
	throw 404;
}

int maximum(node *r){
	if(r!=NULL){
		while(r->right!=NULL)
			r = r->right;
		return r->item;
	}
	throw 404;
}

int main(){
	node *tree = NULL;
	cout<<count(tree)<<endl;
	rinsert(&tree,6);
	rinsert(&tree,67);
	rinsert(&tree,-56);
	rinsert(&tree,18);
	rinsert(&tree,123);
	rinsert(&tree,0);

	cout<<count(tree)<<endl;
	levelOrder(tree);
	preOrder(tree);
	cout<<endl;
	inOrder(tree);
	cout<<endl;
	postOrder(tree);
	cout<<endl;
	return 0;
}

