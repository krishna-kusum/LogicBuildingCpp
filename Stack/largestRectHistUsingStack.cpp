#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int maxArea(vector<int> a){
     
    std::stack<int> s;
    int ans = 0, i = 0;
    int n = a.size();
    a.push_back(0);
    
    while(i<n){
        
        while(!s.empty() && a[s.top()] > a[i]){
            
            int t = s.top();
            int h = a[t];
            
            s.pop();
            if(s.empty()){
                ans = max(ans, h*i);
            }else{
                int width = i-s.top()-1;
                ans = max(ans, width*h);
            }
        }
        s.push(i);
        i++;
    }
    
    return ans;
}

int main(){
 
 std::vector<int> v = {2,1,5,6,2,3};   
    std::cout << maxArea(v) << std::endl;
    
    return 0;
}
