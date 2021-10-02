#include<iostream>
#include<queue>

class node{
    public:
    int data;
    node* left, *right;
    node(int val){
        data = val;
        left = right = NULL;
    }
};

//level order traversal using queue
void printLevelOrder(node* root){
    
    if(!root) return;
    
    std::queue<node*> q;
    
    //push root to queue
    q.push(root);
    
    while(!q.empty()){
        
        node* temp = q.front();
        //print node data
        std::cout<<temp->data<<" ";
        q.pop();
        
        //push node children if exists
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    
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

//Time Complexity : - O(n);
