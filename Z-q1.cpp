#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

int levels(Node *root){
    if(root==NULL) return 0;
    int ans = 1 + max(levels(root->left),levels(root->right));
    return ans;
}

void nthlevel(Node *root,int currlevel,int reqlevel){  
    if(root==NULL) return ;  
    if(currlevel == reqlevel)cout<<root->val<<" "; 
    nthlevel(root->left,currlevel+1,reqlevel);
    nthlevel(root->right,currlevel+1,reqlevel); 
}

void levelorder(Node *root){
    int n = levels(root);
    for(int i=1 ; i<=n ; i++){
        nthlevel(root,1,i);
        cout<<endl;
    }
}

void inoder(Node *root){
    if(root==NULL) return;
    inoder(root->left);
    cout<<root->val<<" ";
    inoder(root->right);
}


int main(){
    Node *a = new Node(1);  //root
    Node *b = new Node(2);
    Node *c = new Node(3);
    Node *d = new Node(4);
    Node *e = new Node(5);
    Node *f = new Node(6);
    Node *g = new Node(7);
    Node *h = new Node(8);
    Node *i = new Node(9);
    

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    d->left = h;
    d->right = i;
    
    cout<<"binary Tree is ";
    cout<<endl;
    levelorder(a);
    cout<<"inorder trversal is -> ";
    inoder(a);
    

}