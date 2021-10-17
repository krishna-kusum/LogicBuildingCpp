// BALANCED HEIGHT BINARY TREE

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    
    node(int val){
        
        data = val;
        left = right = NULL;
    }
};

//OPTIMISED METHOD O(N)
bool isBalanced(node* root, int* height){
    
    if(root ==NULL){
        int* height = 0;
        return true;
    }
    
    int lh =0, rh = 0;
    
    int lbalanced = isBalanced(root->left, &lh);
    int rbalanced = isBalanced(root->right,&rh);
    
    *height = max(lh,rh) + 1;
    
    if(lbalanced == false){
        return false;
    }
    
    if(rbalanced == false){
        return false;
    }
    if(abs(lh-rh) <= 1){
        return true;
    }
    
    return false;
}

//INORDER TRAVERSAL
void inOrder(node* root){
    
    if(root == NULL){
        return;
    }
    
    inOrder(root ->left);
    std::cout << root->data << " ";
    inOrder(root->right);
}

int main(){
    
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    
    int height = 0;
    cout<<isBalanced(root,&height);
    
    
    return 0;
}

//O(N)
