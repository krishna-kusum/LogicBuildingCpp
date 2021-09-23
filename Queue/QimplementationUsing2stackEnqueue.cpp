#include<iostream>
#include<stack>

struct Queue{
  
  std::stack<int> s1, s2; //2 stacks required
  
  void enqueue(int val){
      //empty s1 into s2
      while(!s1.empty()){
          s2.push(s1.top());
          s1.pop();
      }
      
      //push new data
      s1.push(val);
      
      //reversing
      while(!s2.empty()){
          s1.push(s2.top());
          s2.pop();
      }
      
  }
  
  int dequeue(){
      
      if(s1.empty()){
         std::cout<<"empty stack"<<"\n";
         exit(0);
      }
      
      int x = s1.top();
      s1.pop();
      return x;
  }
    
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    
    std::cout<<q.dequeue()<<" ";
    std::cout<<q.dequeue()<<" ";
    std::cout<<q.dequeue()<<" ";
    std::cout<<q.dequeue()<<" ";
    std::cout<<q.dequeue()<<" ";
    std::cout<<q.dequeue()<<" ";
    std::cout<<q.dequeue()<<" ";
    std::cout<<q.dequeue()<<" ";
    
    return 0;
}
