// priority queue
#include<iostream>

class node{
    public:
    int data;
    int priority;
    node* next;
    
    node(int val, int pr){
        data = val;
        priority = pr;
        next = NULL;
    }
};


//enqueue
void push(node* &head, int data, int priority){
 
    node* newnode = new node(data, priority);
    if(head == NULL){
        head = newnode;
        return;
    }
    
    if(newnode->priority > head->priority){
        newnode->next = head;
        head = newnode;
        return;
    }
    
    node* temp = head;
    
    while(temp->next != NULL && temp->next->next->priority > priority){
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

//dequeue
int pop(node* &head){
    if(head == NULL)
        return -1;

    node* temp = head;
    int val = temp->data;
    
    head = head->next;
    free(temp);
    
    return val;
}

//peek
int peek(node* head){
    
    if(head== NULL)
        return -1;
    
    int val = head->data;
    return val;
}


int main(){
    node* head = new node(0,0);
    // node* head = NULL; /specifying as void pointer is necessary

    push(head, 10, 1);
    push(head, 30, 2);
    push(head, 15, 2);
    push(head, 20, 4);
    
    while(head!= NULL){
        std::cout<<peek(head)<<" ";
    
        pop(head);
    }
    
    
    return 0;
}
