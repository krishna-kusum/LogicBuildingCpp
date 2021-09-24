#include<iostream>
#include<stack>

struct Queue{
  
  std::stack<int> s;
  
  //enqueue
  void enqueue(int val){
      s.push(val);
  }
  
  //dequeue
  int dequeue(){
      
    if(s.empty())
        exit(0);
    
    //if stack contains only 1 item
    //base case
    int x = s.top();
    s.pop();
    
    if(s.empty())
        return x;
        
    
    int item = dequeue();
    
    s.push(x);
    
    return item;    
    
  }
    
};


int main(){
    
    Queue q;
    q.enqueue(10);
    q.enqueue(90);
    q.enqueue(30);
    q.enqueue(50);
    q.enqueue(70);
    
    std::cout<<q.dequeue()<<"\n";
    std::cout<<q.dequeue()<<"\n";
    std::cout<<q.dequeue()<<"\n";
    std::cout<<q.dequeue()<<"\n";
    std::cout<<q.dequeue()<<"\n";
    std::cout<<q.dequeue()<<"\n";
    
    return 0;
}
