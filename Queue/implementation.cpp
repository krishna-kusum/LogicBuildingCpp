#include<iostream>
#include<climits>

class Queue{
  
  public:
    int front, rear, size;
    unsigned capacity;
    
    int* array;
    
};

//creating an empty Queue
Queue* createQueue(unsigned capacity){
    
    Queue* queue = new Queue();
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    
    queue->rear = capacity-1;
    queue->array = new int[queue->capacity];
    
    return queue;
}

//isFull
int isFull(Queue* queue){
    return queue->size == queue->capacity;
}

//isEmpty
int isEmpty(Queue* queue){
    return queue->size == 0;
}

//enqueue
void enqueue(Queue* queue, int data){
    if(isFull(queue))
        return;
        
    queue->rear = (queue->rear + 1)%(queue->capacity);
    queue->array[queue->rear] = data;
    queue->size += 1;
    std::cout<<queue->array[queue->rear]<<" ";
}

//dequeue
int dequeue(Queue* queue){
    if(isEmpty(queue))
        return INT_MIN;
        
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)%queue->capacity;
    
    queue->size = queue->size -1;
    
    return item;
}

//access front item
int queueFront(Queue* queue){
    if(isEmpty(queue))
        return INT_MIN;
        
    return queue->array[queue->front];
}

//access rear item
int queueRear(Queue* queue){
    if(isEmpty(queue))
        return INT_MIN;
        
    return queue->array[queue->rear];
}

int main(){
    
    Queue* queue = createQueue(1000);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    
    std::cout<<"\n"<<dequeue(queue)<<"\n";
    std::cout<<queueFront(queue)<<"\n";
    
    std::cout<<queueRear(queue)<<"\n";
    
    while(!isEmpty(queue)){
        std::cout<<dequeue(queue)<<" ";
    }
    return 0;
}
