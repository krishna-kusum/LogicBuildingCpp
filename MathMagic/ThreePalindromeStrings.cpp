#include<iostream>
#include<string>
#include<algorithm>

//function to check palindrome
bool palindrome(std::string s){
    
    //if 1 char return true
    if(s.length() == 1) return true;
    
    std::string s1 = s;

    std::reverse(s.begin(), s.end());

    return s1==s;
}

//driver code
int main(){
    
    std::string s,s1,s2,s3;
    std::cin>>s;
    
    int l = s.length();
    
    for(int i = 1; i<l-1; i++){
        
        //for 1st sub string
        s1 = s.substr(0,i);
        //if palindrome; proceed for 2nd string
        if(palindrome(s1)){
            
            for(int j = i; j<l-i; j++){
            //for 2nd substring
                s2 = s.substr(i, j);
                
                //for 3rd substring
                s3 = s.substr(i+j, l-i-j);
                if(palindrome(s2) && palindrome(s3)){
                    
                    //print strings
                    std::cout<<s1<<"\n"<<s2<<"\n"<<s3;
                    return 0;
                }
            }
            
        }
    }
    
    std::cout<<"Impossible";
    
    return 0;
}
