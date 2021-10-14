#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>

using namespace std;

int trapRainwater(vector<int> a, int n){
    
    stack<int> s;
    int ans = 0;
    
    for(int i = 0; i<n; i++){
        
        while(!s.empty() && a[s.top()] < a[i]){
            
            int curr = s.top();
            s.pop();
            if(s.empty())
                break;
                
            int width = i - 1 - s.top();
            ans += (min(a[s.top()],a[i]) - a[curr])*width;
        }
        s.push(i);
    }
    return ans;    
}

int main(){
    
    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = arr.size();
    
    cout<<trapRainwater(arr, n);
    
    return 0;
}
