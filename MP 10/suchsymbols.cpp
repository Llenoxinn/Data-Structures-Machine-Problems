#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
  string item;
  TreeNode* left;
  TreeNode* right;
  
  TreeNode() {
      item="";
      left=NULL;
      right=NULL;
  }
  TreeNode(string str) {
      item=str;
      left=NULL;
      right=NULL;
  }
};

TreeNode* build(string str) {
    // in such a way i have to do some
    // parsing/separation of substrings!
    TreeNode* tree = new TreeNode();
    int position=-1;
    
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i]=='+' || str[i]=='-') {
            position=i;
        }
    }
    
    if(position == -1) {
        for(int i = 0; str[i] != '\0'; i++) {
            if(str[i]=='*' || str[i]=='/') {
                position=i;
            }
        }
    }
    if(position==-1) {
        tree->item=str;
        return tree;
    }
    tree->item = str[position];
    tree->left=build(str.substr(0,position));
    tree->right=build(str.substr(position+1));
    return tree;
}


void preOrder(TreeNode *r) {
    if(r==NULL) return;
    cout << r->item << " ";
    preOrder(r->left);
    preOrder(r->right);
}

void postOrder(TreeNode *r) {
    if(r==NULL) return;
    // found the error haahgsahghashghasg
    // used the preOrder function to do postorder hahahahahah dumb ahhhhhh
    // preOrder(r->left);
    // preOrder(r->right);
    postOrder(r->left);
    postOrder(r->right);
    cout << r->item << " ";
}

// changed from int to another.
// tried double but its output is 2.14748e+09!!!
// changing to long and check if it fits!

// LONG IS TTHE RIGHT ONE
long solve(TreeNode *r) {
    if(r==NULL) return 0;
    if(r->left==NULL && r->right==NULL) {
        long val=0;   
        for(int i = 0; r->item[i]!='\0';i++) {
            val = val*10 + ((r->item[i])-'0');
        }
        return val;
    }
    else {
        long le = solve(r->left);
        long ri = solve(r->right);
        
        if(r->item=="+") return le + ri;
        if(r->item=="-") return le - ri;
        if(r->item=="*") return le * ri;
        return le/ri;
    }
}


int main() {
    string str;
    while(cin >> str) {
        TreeNode* r = build(str);
        preOrder(r);
        cout << endl;
        // cout<<"That was PreOrder"<<endl;
        postOrder(r);
        cout << endl;
        // cout<<"That was PostOrder"<<endl;
        cout << solve(r) << endl;
        // cout<<"That was Solving"<<endl;
    }
    return 0;
}