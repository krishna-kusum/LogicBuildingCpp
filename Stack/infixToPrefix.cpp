#include<iostream>
#include<stack>
#include<string.h>
#include<algorithm>

//function for precedence
int prec(char c){
    
    if(c == '^')
        return 3;
    else if(c == '/'|| c== '*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
        
    return -1;
}

//infix to postfix
std::string postfix(std::string s){
    
    std::stack<char> stk;
    std::string res;
    
    for(int i = 0; i<s.length(); i++){
        
        char c = s[i];
        if((c>='a' && c<= 'z') || (c>='A' && c<='Z') || (c>='0'&& c<='9'))
            res += c;
        //if opening brace
        else if(c=='(')
            stk.push(c);
        //if closing brace
        else if(c== ')'){
            while(stk.top()!='(' && !stk.empty()){
                res += stk.top();
                stk.pop();
            }
            
            stk.pop();
        }
        //if space
        else if(c==' ')
            res+=c;
        //if operator
        else{
            if(c == '^'){
               while(!stk.empty()&& prec(s[i]) <= prec(stk.top())){
                res+= stk.top();
                stk.pop();
                }  
            }else{
            while(!stk.empty() && prec(s[i]) < prec(stk.top())){
                res+= stk.top();
                stk.pop();
                }
            }
                stk.push(c);
        }
    }
    
    //emptying the stack
    while(!stk.empty()){
        res += stk.top();
        stk.pop();
    }
    
    // std::cout<<res<<"\n";
    return res;
}

//infix to prefix
std::string prefix(std::string infix){
    
    std::reverse(infix.begin(), infix.end());
    
    for(int i = 0; i<infix.size(); i++){
        if(infix[i] == '(')
            infix[i] = ')';
            
        else if(infix[i] == ')')
            infix[i] = '(';
    }
    
    std::string prefix = postfix(infix);
    
    std::reverse(prefix.begin(), prefix.end());
    
    return prefix;
}



int main(){
    
    std::string exprsn = "a+b*(c^d-e)^(f+g*h)-i";//including spaces don't work
    std::cout<<prefix(exprsn);
    
    return 0;
}
