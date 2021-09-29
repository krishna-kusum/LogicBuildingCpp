#include<iostream>

class node{
    public:
    int data;
    node* left;
    node* right;
    
    node(int val){
        data = val;
        
        left = NULL;
        right = NULL;
    }
};


//inorder traversal
void inorder(node* root){
    
    if(root == NULL)
        return;
        
    inorder(root->left);
    std::cout<<root->data<<" ";
    inorder(root->right);
    
}

//preorder traversal
void preorder(node* root){
    
    if(root == NULL)
        return;
        
    std::cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    
}

//postorder traversal
void postorder(node* root){
    
    if(root == NULL)
        return;
        
    preorder(root->left);
    preorder(root->right);
    std::cout<<root->data<<" ";
}


int main(){
  
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    
    inorder(root);
    std::cout<<std::endl;
    preorder(root);
    std::cout<<std::endl;
    postorder(root);
    
    return 0;
}
