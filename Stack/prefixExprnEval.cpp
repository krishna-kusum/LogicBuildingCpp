 //prefix evaluation using std::stack<T> ;
 #include<iostream>
 #include<string>
 #include<stack>
 #include<math.h>
 
 using namespace std;
 
 int prefixEvaluation(string s){
     
    stack<int> st;
    int i = s.length()-1;
    for(i; i>=0; i--){
        
        if(s[i] >='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }else{
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            
            switch(s[i]){
                case '+': st.push(op1+op2);
                break;
                
                case '-': st.push(op1-op2);
                break;
                
                case '*': st.push(op1*op2);
                break;
                
                case '/':st.push(op1/op2);
                break;
                
                default: break;
            }
        }
    }
    
    return st.top();
    
 }
 
 
 int main(){
     
     cout<<prefixEvaluation("-+7*45+20")<<"\n";
     
     return 0;
 }
