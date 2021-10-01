#include<iostream>

//tree node
struct node{
    int data;
    struct node* left;
    struct node* right;
    
    node(int val){
        this->data = val;
    
        left = NULL;
        right = NULL;
    }
};

//searching 
struct node* search(struct node* root, int val){
    //base case
    //if found or reached NULL
    if(root ==  NULL || root->data == val ){
        return root;
    }
    
    //if val is less than root->data; search leftsubtree
    if(val < root->data){
        return search(root->left, val);
    }
    
    //if val is greater than root->data; search rightsubtree
    if(val > root->data){
        return search(root->right, val);
    }
    return NULL;
}

//driver function
int main(){
    
    struct node* root = new node(4);
    root->left = new node(2);
    root->right = new node(6);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->left = new node(5);
    
    struct node* found = search(root, 2);
    std::cout<<found->left->data<<" "<<found->data<<" "<<found->right->data;
    
    return 0;
}
