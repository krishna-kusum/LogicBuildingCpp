#include<iostream>
#include<climits>

class Queue{
  
  public:
  int front, rear, size;
  int* arr;
  
  Queue(int s){
      
      size = s;//size of array
      front = rear = -1;//pointers
      arr = new int[s];//array
  }
  
  void enqueue(int val);
  int dequeue();
  void display();
    
};

void Queue::enqueue(int val){
    
    if((rear == size -1 && front == 0) || rear == (front-1)%(size - 1)){
        std::cout<<"The queue is Full!"<<"\n";
        return;
    }
    if(rear == -1){
        front = rear = 0;
        arr[rear] = val;
        return;
    }
    
    rear = (rear + 1)%(size);
    arr[rear] = val;
}


int Queue::dequeue(){
    if(front == -1){
        std::cout<<"Queue is empty."<<"\n";
        return INT_MIN;
    }
    
    int data = arr[front];
    arr[front] = -1;
    if(front == rear){
        front = -1;
        rear = -1;
    }else {
        front = (front + 1)%(size);
    } 
    
    return data;
}

void Queue::display(){
    
    if(front == -1){
        std::cout<<"Queue is empty!"<<"\n";
        return;
    }
    
    if(rear>=front){
    for(int i = front; i<=rear; i++){
        std::cout<<arr[i]<<" ";
    }
    }else{
        for(int i = front; i<=size-1; i++){
            std::cout<<arr[i]<<" ";
        }
        
        for(int i =0; i<=rear; i++){
            std::cout<<arr[i]<<" ";
        }
    }
    
}


int main(){
    
    Queue q(6);
    q.enqueue(10);
    q.enqueue(23);
    q.enqueue(4);
    q.enqueue(-5);
    q.enqueue(899);
    q.enqueue(34);
    
    std::cout<<q.dequeue()<<" dequeued \n";
    std::cout<<q.dequeue()<<" dequeued \n";

    q.enqueue(675);
    
    q.display();
    
    return 0;
}
