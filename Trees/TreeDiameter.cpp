//DIAMETER OF A TREE


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

//height OF TREE
int height(node* root){
    
    //if null 
    if(root == NULL){
        return 0;
    }
    
    return max(height(root->left), height(root->right)) + 1;
}

//DIAMETER OF TREE

int diameter(node* root){
    //base case
    if(root == NULL){
        return 0;
    }
    
    int lheight = height(root->left);//left subtree height
    int rheight = height(root->right);//right subtree height 
    
    int Currdiameter = lheight + rheight + 1;
    
    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);
    
    return max(Currdiameter, max(ldiameter, rdiameter));
}

int main(){
    
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    
    std::cout << diameter(root);
    
    return 0;
}
