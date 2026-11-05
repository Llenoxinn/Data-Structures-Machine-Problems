#include<iostream>

class node{
public:
int item;
node *left, *right, *parent;
node(int x){
item = x;
left = right = parent = NULL;
}
};

class BST {
    public:
        node* r;
        BST() {
            r = NULL;
        }
       
        node* search(node *t, int a) {
            node* current = t;
            while(current!=NULL) {
                if(a==current->item) return current;
                else if (a < current->item) current = current->left;
                else current = current->right;
            }
            return NULL;
        }
       
        void rinsert(node **t, int x){
        if(*t == NULL)
        *t = new node(x);
        else{
        if(x < (*t)->item) {
        rinsert(&((*t)->left),x);
        (*t)->left->parent=*t;
        }
        else {
        rinsert(&((*t)->right),x);
        (*t)->right->parent=*t;
        }
        }
        }
       
        // bool ancestor(int a, int b) {
        //     if(a==b) return false;
        //     node* ancestorA = search(r, a);
        //     if(ancestorA == NULL) return false;
           
        //     node* ancestorB = search(ancestorA, b);
        //     if(ancestorB!=NULL) return true;
           
        //     return false;
        // }
       
        bool ancestor(int a, int b) {
            if(a==b) return false;
            node *curr=r;
            while(curr!=NULL && curr->item != a) {
                // if(curr->item==a) return true;
                if (a<curr->item) curr = curr->left;
                else curr = curr->right;
            }
            if(curr==NULL) return false;
           
            while(curr!=NULL) {
                if(curr->item==b) return true;
                else if (b<curr->item) curr = curr->left;
                else curr = curr->right;
            }
            return false;
        }
       
        bool descendant(int a, int b) {
            return ancestor(b,a);
        }
       
        int successor(int a) {
            node* curr = search(r, a);
            if(curr==NULL) return a;
            while(curr->right!=NULL) {
                curr = curr->right;
                while(curr->left!=NULL) {
                    curr=curr->left;
                }
                return curr->item;
            }
            node *p = curr->parent;
            while(p!=NULL && curr == p->right) {
                curr=p;
                p=p->parent;
            }
            if(p==NULL) return a;
            return p->item;
        }
       
        int predecessor(int a) {
            node* curr = search(r, a);
            if(curr==NULL) return a;
            while(curr->left!=NULL) {
                curr = curr->left;
                while(curr->right!=NULL) {
                    curr=curr->right;
                }
                return curr->item;
            }
            node *p = curr->parent;
            while(p!=NULL && curr == p->left) {
                curr=p;
                p=p->parent;
            }
            if(p==NULL) return a;
            return p->item;
        }
};
int main() {
    int n;
    std::cin >> n;
    BST bst;
    for(int i = 0; i<n; i++) {
        int m;
        std::cin >> m;
        bst.rinsert(&bst.r, m);
    }
   
    int a, b;
    std::cin >> a >> b;
    // printf("Is %i an ancestor of %i.\n", a, b);
    std::cout << (bst.ancestor(a,b) ? "Laozi" : "Mushu") << std::endl;
   
    std::cin >> a >> b;
    // printf("Is %i a descendant of %i.\n", a, b);
    std::cout << (bst.descendant(a,b) ? "Mulan" : "Mushu") << std::endl;
   
    // printf("This is successor and predecessor CASE.\n");
    std::cin >> a >> b;
    int l = bst.successor(a);
    int q = bst.predecessor(b);
    if(l!=a) {
        std::cout << l << std::endl;
    } else
        std::cout << "Li Shang" << std::endl;
    if(q!=b) {
        std::cout << q << std::endl;
    } else
        std::cout << "Li Shang" << std::endl;
    // // while(n--) {
    // //     node* bst = NULL;
    // //     int a, b;
    // //     cin >> a;
    // //     cin >> b;
    // //     insert(&bst, a);
    // //     insert(&bst, b);
    // //     ancestor(a,b);
       
    // //     cin >> c;
    // //     cin >> d;
       
    // //     insert(&bst, c);
    // //     insert(&bst, d);
    // //     descendant(c,d);
       
    // //     cin >> e;
    // //     insert()
    // // }
    return 0;
    }

// node* search(node *t, int a) {
//     node* current = t;
//     while(current!=NULL) {
//         if(a==current->item) return current;
//         else if (a < current->item) current = current->left;
//         else current = current->right;
//     }
// }

// void rinsert(node **t, int x){
// if(*t == NULL)
// *t = new node(x);
// else{
// if(x < (*t)->item)
// rinsert(&((*t)->left),x);
// (*t)->left->parent=*t;
// else
// rinsert(&((*t)->right),x);
// (*t)->right->parent=*t;
// }
// }

// bool ancestor(int a, int b) {
//     if(a==b) return false;
//     node* ancestorA = search(bst, a);
//     if(ancestorA == NULL) return false;
   
//     node* ancestorB = search(ancestorA, b);
//     if(ancestorB!=NULL) return true;
   
//     return false;
// }

// bool descendant(int a, int b) {
//     return ancestor(b,a);
// }

// int successor(int a) {
//     node* curr = search(bst, a);
// }

// int predecessor(int a) {
//     node* curr = search(bst, a);
// }