#include<iostream>
#include<string.h>
#include<stack>
#include<algorithm>
#include<typeinfo>

//operator check
bool isOperator(char c){
    
    switch(c){
        
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            return true;
    }
    
    return false;
}

//postfix to prefix
std::string postToPre(std::string postfix){
    
    std::stack<std::string> stk;
    
    std::string ans = "";
    
    for(int i = 0; i<postfix.size(); i++){
        
        //if operator
        if(isOperator(postfix[i])){
            std::string op1 = stk.top();
            stk.pop();
            
            std::string op2 = stk.top();
            stk.pop();
            
            std::string temp = postfix[i] + op2 + op1;
            
            stk.push(temp);
        } //if operand
        else {
            stk.push(std::string(1,postfix[i])); //converting char to string
        }
    }
    
    while(!stk.empty()){
        ans += stk.top();
        stk.pop();
    }
    
    return ans;
}

int main(){
    
    std::string str = "ABC/-AK/L-*";
    
    std::cout<<postToPre(str);
    
}
