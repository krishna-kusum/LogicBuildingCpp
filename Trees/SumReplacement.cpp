//SUM REPLACEMENT


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

//METHOD 1 
//SUM of nodes REPLACEMENT
int nodeSum(node* root){
    
    if(root == NULL){
        return 0;
    }
    
    int lsum = nodeSum(root->left);
    int rsum = nodeSum(root->right);
    
    root->data = root->data + lsum + rsum;
    
    return root->data;
}

//METHOD 2 
//SUM REPLACE 
void sumReplace(node* root){
    
    if(root == NULL)
        return;
        
    sumReplace(root->left);
    sumReplace(root->right);
    
    if(root->left)
        root->data += root->left->data;
        
    if(root->right)
        root->data += root->right->data;
    
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
    
    inOrder(root);
    std::cout<<endl;
    // nodeSum(root);
    sumReplace(root);
    inOrder(root);
    
    
    return 0;
}
