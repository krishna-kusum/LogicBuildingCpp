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

//deleteAtPos
void deleteAtPos(node* &head, int pos){
    
    if(head == NULL){
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
    
    node* deleteNode = temp->next;
    
    temp->next = temp->next->next;
    delete deleteNode;
}

//deletionAtBegin
void deleteAtStart(node* &head){
    node* deleteNode = head;
    head = head->next;
    delete deleteNode;
}

//delete at end
void deleteAtEnd(node* &head){
    
    node* temp = head;
    
    while(temp->next->next){
        temp = temp->next;
        
    }
    
    node* deleteNode = temp->next;
    temp->next = NULL;
    delete deleteNode;
    
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
    
    display(head);
    std::cout<<"\n";
    deleteAtPos(head, 3);
    display(head);
    std::cout<<"\n";
    deleteAtStart(head);
    display(head);
    std::cout<<"\n";
    deleteAtEnd(head);
    display(head);
    
    return 0;
}
