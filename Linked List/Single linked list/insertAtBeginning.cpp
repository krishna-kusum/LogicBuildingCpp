#include<iostream>

class node{
    
    public:
        int data;
        node* next;
        
    node(int val){
        data = val;
        next = NULL;
    }
};

//insert at beginning
void insertAtBeginning(int data, node* &head){
    
    node* newnode = new node(data);
    newnode->next = head;
    head = newnode;
}

//display
void display(node* ptr){
    
    while(ptr != NULL){
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
}


int main(){
    node* head = new node(9); 
    insertAtBeginning(5, head);
    
    display(head);
    
    
    return 0;
}
