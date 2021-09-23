#include<iostream>
#include<stack>
#include<queue>

//printing queue
void print(std::queue<int>& Q){
    while(!Q.empty()){
        std::cout<<Q.front()<<" ";
        Q.pop();
    }
}

//revresing the queue
void reverseQ(std::queue<int>& Q){
    
    std::stack<int> stk;
    
    while(!Q.empty()){
        stk.push(Q.front());
        Q.pop();
    }
    
    while(!stk.empty()){
        Q.push(stk.top());
        stk.pop();
    }
}

int main(){
    
    std::queue<int> Q;
    Q.push(10);
    Q.push(20);
    Q.push(30);
    Q.push(40);
    Q.push(50);
    Q.push(60);
    Q.push(70);
    Q.push(80);
    Q.push(90);
    Q.push(100);
    
    reverseQ(Q);
    print(Q);
    
    return 0;
}
