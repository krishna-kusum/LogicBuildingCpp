//Tree Level Order traversal 
#include<iostream>

class node{
    public:
    int data;
    node* left, *right;
    
    node(int val){
        data = val;
        left = right = NULL;
    }
    
};

//height of the tree 
int height(node* root){
    //if root is null 
    if(!root){
        return 0;
    }
    
    //left subtree height
    int lheight = height(root->left) + 1;
    //right subtree height
    int rheight = height(root->right) + 1;
    
    //return greater of the two
    return lheight>rheight ? lheight : rheight;
}

//print current level nodes
void printCurrLevel(node* root, int level){
    
    //if root is null 
    if(!root) return;
    
    //if level is 1; print node data
    if(level == 1) std::cout<<root->data<<" ";
    
    //if level greater than 1; traverse to level == 1 
    else if (level > 1){
        printCurrLevel(root->left, level-1);
        printCurrLevel(root->right, level-1);
    }
}

//print level order of the tree 
void printLevelOrder(node* root){
    //if empty
    if(!root) return;
    
    //height of tree 
    int h = height(root);
    
    //traverse through tree levels
    for(int i = 1; i<=h; i++)
        printCurrLevel(root, i);
}

int main(){
    
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    
    printLevelOrder(root);
    
    return 0;
}
