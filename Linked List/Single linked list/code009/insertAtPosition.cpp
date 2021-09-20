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

//insert at head 
void insertAtHead(int data, node* &head){
    node* newnode = new node(data);
    newnode->next = head;
    head = newnode;
}

//insert at tail

void insertAtTail(int data, node* &head){
    node* newnode = new node(data);
    if(head == NULL){
        head = newnode;
        return;
    }
    
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    
}

//insertAtPos
void insertAtPos(int data, node* &head, int pos){
    
    node* newnode = new node(data);
    
    if(head == NULL){
        insertAtHead(data, head);
        return;
    }
    
    int count = 1;
    
    node* temp = head;
    while(count<pos-1){
        temp = temp->next;
        count++;
        if(temp == NULL){
        return;
    }
    }
    
    newnode->next = temp->next;
    
    temp->next = newnode;
}

void display(node* head){
    
    node* temp = head;
    while(temp != NULL){
        std::cout << temp->data << std::endl;
        temp = temp->next;
        
    }
}

int main(){
    
    node* head = new node(1);
    insertAtTail(2,head);
    insertAtTail(3,head);
    
    insertAtHead(4,head);
    insertAtPos(9,head, 3);
    
    // display(head);
    
    display(head);
    
    return 0;
}
