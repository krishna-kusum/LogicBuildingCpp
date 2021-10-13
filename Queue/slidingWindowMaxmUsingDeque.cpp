 #include<iostream>
 #include<deque>
 #include<vector>
using namespace std;

int main(){
    
    int n,k;
    cin>>n>>k;
    std::vector<int> v(n);
    
    for(auto &i: v)
        cin>>i;
        
    deque<int> q;
    
    vector<int> ans;
    
    for(int i = 0; i<k; i++){
        while(!q.empty() && v[q.back()] < v[i]){
            q.pop_back();
        }
        q.push_back(i);
    }
    
    ans.push_back(v[q.front()]);
    
    for(int i = k; i<n; i++){
        
        if(q.front() == i-k){
            q.pop_back();
        }
          while(!q.empty() && v[q.back()] < v[i]){
            q.pop_back();
        }
        q.push_back(i);
        
        ans.push_back(v[q.front()]);
    }
    
    for(auto i : ans){
        std::cout << i << " ";
    }
    
    return 0;
} 

//O(1)
