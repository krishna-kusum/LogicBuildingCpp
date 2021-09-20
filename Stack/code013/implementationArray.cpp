#include<iostream>

#define MAX 10000
class Stack{
    
    int top;
    public:
    int arr[MAX];//declaring Stack
    Stack(){
        top = -1;
    }
    
    bool push(int val);
    int pop();
    int peek();
    bool isEmpty();
};

//pushing elements into the Stack
bool Stack::push(int val){
    if(top>=(MAX -1)){
        std::cout << "Stack Overflow" << std::endl;
        return false;
    }
    
    arr[++top] = val;
    std::cout<<arr[top]<<" ";
    return true;
}

//popping
int Stack::pop(){
    
    if(top<0){
        std::cout<<"Stack Underflow"<<std::endl;
        return 0;
    }
    
    return arr[top--];
}


//peeking
int Stack::peek(){
    
    if(top<0){
        std::cout<<"Stack Underflow"<<std::endl;
        return 0;
    }
    
    return arr[top];
}

//isEmpty
bool Stack::isEmpty(){
    return top<0;
}


int main(){
    
    class Stack s;
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    
    std::cout<<s.pop()<<std::endl;
    
    while(!s.isEmpty()){
        std::cout<<s.peek()<<"\n";
    
        s.pop();
    }
    
    return 0;
}
