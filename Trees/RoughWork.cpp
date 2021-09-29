//Inorder Traversal Without traversal
#include<iostream>
#include<stack>

// using namespace std;
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

void inOrderWoRecursion(struct node* root){
    
    std::stack<struct node*> s;
    
    struct node* temp = root;
    
    while(temp != NULL){
        s.push(temp);
        temp = temp->left;
    }//code gone wrong    
    
    while(temp != NULL || !s.empty()){
        temp = s.top();
        std::cout<<temp->data<<" ";
        s.pop();
        
        temp = temp->right;
        if(temp){
            s.push(temp);
        }
        // }
        // if(temp->left){
        //     s.push(temp->left);
        // }
    }
    
}

int main(){
    
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    
    inOrderWoRecursion(root);
    
    return 0;
}
