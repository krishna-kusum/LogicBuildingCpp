//queue using stack dequeue
#include<iostream>
#include<stack>

struct Queue {
    
    std::stack<int> s1, s2;
    
    void enqueue(int val){
        
        s1.push(val);
        
    }
    
    int dequeue(){
        
        if(s1.empty() && s2.empty()){
            std::cout<<"Queue is empty"<<"\n";
            return 0;
        }
        
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        int x = s2.top();
        s2.pop();
        
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
    
    
    std::cout<<q.dequeue()<<" ";
    std::cout<<q.dequeue()<<" ";
    std::cout<<q.dequeue()<<" ";
    std::cout<<q.dequeue()<<" ";
    std::cout<<q.dequeue()<<" ";
    
    
    return 0;
}
