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
	if(*r!=NULL){
		queue<node*> q;
		q.push(*r);
		node *n = new node(x);
		do{
			node *d = q.front();
			q.pop();
			// cout<<d->item<<" ";
			if(d->left==NULL){
				d->left = n;
				n->parent = d;
				break;
			}
			else
				q.push(d->left);
			
			if(d->right==NULL){
				d->right = n;
				n->parent = d;
				break;
			}
			else
				q.push(d->right);
		}while(!q.empty());
	}
	else{
		*r = new node(x);
	}
}

int count(node *n){
	if(n==NULL)
		return 0;
	else
		return 1 + count(n->left) + count(n->right);
}

int main(){
	node *tree = NULL;
	cout<<count(tree)<<endl;
	for(int i=0; i<5; i++){
		insert(&tree,i);
		cout<<count(tree)<<endl;
	}
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

