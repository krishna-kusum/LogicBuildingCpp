#include <iostream>
#include<climits>

class StackNode{
  public:
  int data;
  StackNode* next;
};

//createNode
StackNode* createNode(int data){
    
    StackNode* newnode = new StackNode();
    newnode->data = data;
    newnode->next = NULL;
    
    return newnode;
}

//isEmpty
bool isEmpty(StackNode* root){
    
    return !root;
}

//push
StackNode* push(StackNode** root, int data){
    
    StackNode* newnode = createNode(data);
    newnode->next = *root;
    *root = newnode;
    std::cout<<newnode->data<<" ";
    return newnode;
}

//popping
int pop(StackNode** root){
    if(isEmpty(*root))
        return INT_MIN;
        
    StackNode* temp = *root;
    *root = (*root)->next;
    
    int popped = temp->data;
    free(temp);
    
    return popped;
}

//peeking
int peek(StackNode* root){
    if(isEmpty(root))
        return INT_MIN;
        
    return root->data;
}


int main(){
    
    StackNode* root = NULL;
    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
    push(&root, 40);
    
    std::cout<<pop(&root)<<"\n";
    std::cout<<peek(root)<<"\n";
    
    return 0;
}
