//preorder traversal using stack

#include<iostream>
#include<stack>

struct node{
    int data;
    struct node* left;
    struct node* right;
    
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

//preorder without Recursion
void preorderWOrecursion(struct node* root){
    
    std::stack<struct node*> s;
    struct node* curr = root;
    
    s.push(curr); //push root node
    
    while(!s.empty()){
       curr = s.top();
       
       std::cout<<curr->data<<" ";
       s.pop();
       
       //right element push
       if(curr->right) s.push(curr->right);
       //left element push
       if(curr->left) s.push(curr->left);
    }
}

//post order without recursion
void postorderWOrecursion(struct node* root){
    
    std::stack<struct node*> s;
    struct node* curr = root;
    
    s.push(curr); //push root node
    
    while(!s.empty()){
       
       //right element push
       if(curr->right) s.push(curr->right);
       //left element push
       if(curr->left) s.push(curr->left);
       
       //print node
       curr = s.top();
       
       std::cout<<curr->data<<" ";
       s.pop();
    }
}


int main(){
    
    struct node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right = new node(5);
    root->right->left = new node(6);
    
    preorderWOrecursion(root);
    
    return 0;
}
