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

//insert at tail
void insertAtTail(node* &head, int data){
    node* temp = head;
    node* newnode = new node(data);
    
    while(temp->next != NULL){
        temp = temp->next;
    }
    
    temp->next = newnode;
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
    
    insertAtTail(head, 8);
    insertAtTail(head, 8);
    insertAtTail(head, 9);
    
    display(head);
    
    
    return 0;
}
