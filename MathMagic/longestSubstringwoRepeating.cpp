 //Longest Substring Without Repeating characters
 
 #include<iostream>
 #include<vector>
 #include<algorithm>
 #include<string>
 #include<algorithm>
 
 using namespace std;
 int main(){
    
    string s;
    cin>>s;
    
    int n = s.size();
    vector<int> dict(256,-1);
    
    int start = -1, maxlen = 0;
    
    for(int i = 0; i<n; i++){
        
        if(dict[s[i]] > start){
            start = dict[s[i]];
        }
        
        dict[s[i]] = i;//storing position of character
        
        if(maxlen != i-start)
        maxlen = max(maxlen, i-start);
    }
    
    std::cout << maxlen << std::endl;
     
    return 0;
 }
 
 
 //O(n)
