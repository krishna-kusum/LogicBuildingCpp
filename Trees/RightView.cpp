#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class node{
    public:
    int data;
    node* left; node* right;
    
    node(int val){
        data = val;
        left = right = NULL;
    }
};

//RIGHT VIEW OF THE TREE
void rightView(node* root){
    
    if(root == NULL){
        return ;
    }
    
    queue<node*> q;
    q.push(root);
    
    while(!q.empty()){
        
        int n = q.size();  
        for(int i = 0; i<n; i++){
            
            node* curr = q.front();
            q.pop();
            
            if(i == n-1)
            cout<<curr->data<<" ";
            
            if(curr->left){
                q.push(curr->left);
            }
            
            if(curr->right){
                q.push(curr->right);
            }
        }        
    }
}


int main(){
    
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    
    rightView(root);
    
    return 0;
}
