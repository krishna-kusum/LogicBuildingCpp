#include<iostream>
#include<stack>
#include<queue>

//printing queue
void print(std::queue<long long int>& Q){
    while(!Q.empty()){
        std::cout<<Q.front()<<" ";
        Q.pop();
    }
}

//queue reversal using recursion
std::queue<long long int> reverseQRecusion(std::queue<long long int>& Q){
    
    //base case
    if(Q.empty())
        return Q;
        
    long long int data = Q.front();
    Q.pop();
    Q = reverseQRecusion(Q);
    Q.push(data);
    
    return Q;
}


int main(){
    
    std::queue<long long int> Q;
    Q.push(0);
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
    
    reverseQRecusion(Q);
    
    print(Q);
    return 0;
}
