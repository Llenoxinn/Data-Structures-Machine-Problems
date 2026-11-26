#include <iostream>
#include <cmath>

using namespace std;

class node{
public:
    int item,height,balance,child;
    node *left,*right,*parent;
    node();
    node(int);
};

class avl{
private:
    node *root;
    void leftrotate(node*);
    void rightrotate(node*);
    void leftrightrotate(node*);
    void rightleftrotate(node*);
    int height(node *n){
        if(n==NULL)
            return -1;
        else
            return n->height;
    }
public:
    avl();
    void insert(int);
    int search(int);
};


int main(){
    int n;
    cin>>n;
    avl t;
    while(n--){
        int item;
        cin>>item;
        t.insert(item);
    }
    cin>>n;
    if(t.search(n)==1) {
        cout << "FOUND" << endl;
    } else {
        cout << "!FOUND" << endl;
    }
    return 0;
}

node::node(){
    left = right = parent = NULL;
    height = 0;
    balance = 0;
    child=0;
}

node::node(int n){
    item = n;
    left = right = parent = NULL;
    height = 0;
    balance = 0;
    child=0;
}

avl::avl(){
    root = NULL;
}

int avl::search(int x) {
    int count=0;
    node *cur = root;
    
    while(cur!=NULL) {
        count++;
        if(cur->item==x) {
            cout << count << " ";
            return 1;
        } else if (cur->item > x) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }    
    }
    
    cout << count << " ";
    return 0;
}

void avl::leftrotate(node *n){
    node* p = n->parent;
	node* r = n->right;
	node* l = r->left;
	r->left = n;
	n->parent = r;
	r->parent = p;
	n->right = l;
	if(l!=NULL){
		l->parent = n;
		l->child = 1;
	}
	if(p!=NULL){
		if(n->child==1)
			p->right = r;
		else
		if(n->child==-1)
			p->left = r;
	}
	else
		root = r;
	n->height = 1+max(height(n->left),height(n->right));
	r->height = 1+max(height(r->left),height(r->right));
// 	r->child=n->child;
// 	n->child=-1;
	
//     int rh = height(n->right);
// 	int lh = height(n->left);

// 	n->height = 1+max(lh,rh);

// 	if(lh > rh)
// 		n->balance = -1;
// 	else
// 	if(rh > lh)
// 		n->balance = 1;
// 	else
// 		n->balance = 0;
		
//     rh = height(r->right);
// 	lh = height(r->left);

// 	r->height = 1+max(lh,rh);

// 	if(lh > rh)
// 		r->balance = -1;
// 	else
// 	if(rh > lh)
// 		r->balance = 1;
// 	else
// 		r->balance = 0;
}
void avl::rightrotate(node *n){
    node* p = n->parent;
	node* r = n->left;
	node* l = r->right;
	r->right = n;
	n->parent = r;
	r->parent = p;
	n->left = l;
	if(l!=NULL){
		l->parent = n;
		l->child = -1;
	}
	if(p!=NULL){
		if(n->child==1)
			p->right = r;
		else
		if(n->child==-1)
			p->left = r;
	}
	else
		root = r;

    n->height = 1+max(height(n->left),height(n->right));
	r->height = 1+max(height(r->left),height(r->right));
// 	r->child=n->child;
// 	n->child=1;
	
//     int rh = height(n->right);
// 	int lh = height(n->left);

// 	n->height = 1+max(lh,rh);

// 	if(lh > rh)
// 		n->balance = -1;
// 	else
// 	if(rh > lh)
// 		n->balance = 1;
// 	else
// 		n->balance = 0;
		
//     rh = height(r->right);
// 	lh = height(r->left);

// 	r->height = 1+max(lh,rh);

// 	if(lh > rh)
// 		r->balance = -1;
// 	else
// 	if(rh > lh)
// 		r->balance = 1;
// 	else
// 		r->balance = 0;
}

// void avl::leftrightrotate(node *n){
//     leftrotate(n->left);
//     rightrotate(n);
// }

// void avl::rightleftrotate(node *n){
//     rightrotate(n->right);
//     leftrotate(n);
// }

void avl::insert(int x){
    node *n = new node(x);
    if(root==NULL)
        root = n;
    else{
        node *tmp = root, *prev;
        while(tmp!=NULL){
            prev = tmp;
            if(x < tmp->item)
                tmp = tmp->left;
            else
                tmp = tmp->right;
        }
        n->parent = prev;
        if(x < prev->item){
            prev->left = n;
            n->child = -1;
        }
        else{
            prev->right = n;
            n->child = 1;
        }

        node *curr = n;
        do{
            int rh = height(curr->right);
			int lh = height(curr->left);

			curr->height = 1+max(lh,rh);

			if(lh > rh)
				curr->balance = -1;
			else
			if(rh > lh)
				curr->balance = 1;
			else
				curr->balance = 0;
            
            int dh = abs(lh-rh);
			if(dh>1){
                //cout<<prev->item<<" "<<curr->item<<endl;
				if(prev->balance == 1 && curr->balance == 1)
					leftrotate(curr);
				else
				if(prev->balance == -1 && curr->balance == -1)
					rightrotate(curr);
				else
				if(prev->balance == -1 && curr->balance == 1){
					rightrotate(prev);
                    leftrotate(curr);
				}
				else
				if(prev->balance == 1 && curr->balance == -1){
					leftrotate(prev);
                    rightrotate(curr);
				}
			}
			prev = curr;
			curr = curr->parent;
		}while(curr!=NULL);
    }
}
