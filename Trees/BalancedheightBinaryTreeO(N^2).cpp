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

//height function
int height(node* root){
    
    if(root == NULL){
        return 0;
    }
    
    return max(height(root->left),height(root->right)) + 1;
}

bool isBalanced(node* root){
    
    if(root ==NULL){
        return true;
    }
    if(isBalanced(root->left) == false){
        return false;
    }
    
    if(isBalanced(root->right) == false){
        return false;
    }
    
    int lheight = height(root->left);
    int rheight = height(root->right);
    
    if(abs(lheight-rheight) <= 1){
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
    
    cout<<isBalanced(root);
    
    
    return 0;
}
