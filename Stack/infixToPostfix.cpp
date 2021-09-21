#include<iostream>
#include<stack>
#include<string.h>


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
void postfix(std::string s){
    
    std::stack<char> stk;
    std::string res;
    
    for(int i = 0; i<s.length(); i++){
        
        char c = s[i];
        if((c>='a' && c<= 'z') || (c>='A' && c<='Z') || (c>='0'&& c<='9'))
            res += c;
        //if opening brace
        else if(c=='(')
            stk.push('(');
        //if closing brace
        else if(c== ')'){
            while(stk.top()!='('){
                res += stk.top();
                stk.pop();
            }
            stk.pop();
        }
        //if operator
        else{
            while(!stk.empty()&& prec(s[i]) <= prec(stk.top())){
                res+= stk.top();
                stk.pop();
            }
            stk.push(c);
        }
    }
    
    //emptying the stack
    while(!stk.empty()){
        res += stk.top();
        stk.pop();
    }
    
    std::cout<<res<<"\n";
}



int main(){
    
    std::string exprsn = "a+b*(c^d-e)^(f+g*h)-i";//including spaces don't work
    postfix(exprsn);
    
    return 0;
}
