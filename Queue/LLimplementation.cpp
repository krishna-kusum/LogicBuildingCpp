#include<iostream>
#include<climits>

struct Qnode{
  
  int data;
  Qnode* next;
  Qnode(int val){
      data = val;
      next = NULL;
  }
};

struct Queue{
   
   Qnode* front, *rear;
   
   Queue(){
       front = rear = NULL;
   }
   
   //enqueue
   void enqueue(int val){
       
       Qnode* temp = new Qnode(val);
       
       if(rear == NULL){
        front = rear = temp;
        std::cout<<rear->data<<" enqueued ";
        return;
       }
       
       rear->next = temp; 
       rear = temp;
        
        std::cout<<rear->data<<" enqueued ";
   }
   
   //dequeue
   int dequeue(){
       if(front == NULL){
           return INT_MIN;
       }
       
       int item = front->data;
       Qnode* temp = front;
       front = front->next;
       
       if(front == NULL){
           rear = NULL;
       }
       
       delete temp;
       
       return item;
   }
   
    
};

int main(){
    
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    std::cout<<"\n"<<q.dequeue()<<"\n";
    std::cout<<q.dequeue()<<"\n";
    q.enqueue(40);
    q.enqueue(50);
    std::cout<<"\n"<<q.dequeue()<<"\n";
    std::cout<<(q.front)->data<<" Front data\n";
    std::cout<<(q.rear)->data<<" Rear data\n";
    
    return 0;
}
