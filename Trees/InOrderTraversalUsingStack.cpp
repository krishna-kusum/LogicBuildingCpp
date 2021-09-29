#include<iostream>
#include<stack>

using namespace std;

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

//function for inorder traversal
void inOrderWOrecusion(struct node* root){
    
    std::stack<struct node*> s;
    struct node* current = root; //pointer to current node
    
    //either node is remaining in tree or stack is not empty
    while(current != NULL || !s.empty()){
        //push all elements of left subtree in the stack
        while(current != NULL){
            s.push(current);
            current = current->left;
        }
        
        //pop elements, print
        current = s.top();
        
        std::cout<<current->data<<" ";//print element 
        
        s.pop();
        
        //traverse right of popped element 
        current = current->right;
        // if(current){
        //     s.push(current);
        // } -> Do not revisit the nodes
    }
    
}

int main(){
    
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->left->right->left = new node(7);
    
    inOrderWOrecusion(root);
    
    return 0;
}
