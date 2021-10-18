//FLATTEN A BINARY TREE

#include<iostream>
#include<queue>
#include<vector>
#include<stack>

using namespace std;

class node{
    public:
    int data;
    node* left, *right;
    
    node(int val){
        data = val;
        left = right = NULL;
    }
};

//FLATTEN function
void flatten(node* root){
    
    if(root == NULL||(root->left == NULL && root->right == NULL)){
        return;
    }
    
    if(root->left != NULL){
        
        flatten(root->left);
        
        node* temp = root->right;
        root->right = root->left;
        
        root->left = NULL;
        
        node* tail = root->right;
        while(tail->right != NULL){
            tail = tail->right;
        }
        
        tail->right = temp;
    }
    
    flatten(root->right);
}

//INORDER PRINT
void inorderPrint(node* root){
    
    if(root == NULL){
        return;
    }
    
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main(){
    
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    
    flatten(root);
    inorderPrint(root);
    
    return 0;
}
