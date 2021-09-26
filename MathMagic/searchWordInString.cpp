#include<iostream>
#include<string.h>

int main(){
    
    std::string s;
    getline(std::cin, s);
    
    std::string word;
    std::cin>>word;
    
    int slen = s.length();
    int wordlen = word.length();
    bool found = 1;
    int count = 0;
    
    for(int i= 0; i<=slen-wordlen; i++){
     found = 1;
     int j;
     for(j = 0; j<wordlen; j++){
        if(s[i+j] != word[j]){
            found = 0;
            break;
        }
     }
    //  i += j; wrong logic
     if(found==1)
        count++;
        
    }
    
    std::cout<<count;
    
    return 0;
}
