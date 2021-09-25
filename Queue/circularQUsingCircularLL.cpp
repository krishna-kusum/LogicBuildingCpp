//circular linked list from queue
#include<iostream>
#include<climits>

class node{
    public:    
    int data;
    node* next;
    
    node(int val){
        data = val;
        next = NULL;
    }
    
};

class circularQueue{
    public:
    node *front = NULL, *rear = NULL; 
    
    void enqueue(int val){
        node* temp = new node(val);
        //if empty
      if(front == NULL)
        front = temp;
      else 
        rear->next = temp;
        
      rear = temp;
      rear->next = front;
    }
    
    
    int dequeue(){
        //if empty
        if(front == NULL){
            std::cout<<"Queue is empty!"<<"\n";
            return INT_MIN;
        }
        
        int val;
        
        //if last node to be deleted
        if(front == rear){
            val = front->data;
            free(front);
            front = NULL;
            rear = NULL;
            
            return val;
        }
        
        node* temp = front;
        val = temp->data;
        
        front = front->next;
        rear->next = front;
        
        free(temp);
        
        return val;
    }
};


int main(){
    
    circularQueue q;
    q.enqueue(10);
    q.enqueue(24);
    q.enqueue(34);
    q.enqueue(45);
    q.enqueue(19);
    q.enqueue(0);
    
    std::cout<<q.dequeue()<<"\n";
    std::cout<<q.dequeue()<<"\n";
    std::cout<<q.dequeue()<<"\n";
    std::cout<<q.dequeue()<<"\n";
    std::cout<<q.dequeue()<<"\n";
    std::cout<<q.dequeue()<<"\n";
    std::cout<<q.dequeue()<<"\n";
    
    return 0;
}
