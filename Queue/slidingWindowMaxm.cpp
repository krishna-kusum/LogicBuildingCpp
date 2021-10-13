//SLIDING WINDOW MAXIMUM

#include<iostream>
#include<deque>
#include<vector>
#include<set>
using namespace std;

int main(){
    
    int n, k;
    cin>>n>>k;
    std::vector<int> v(n);
    
    for(auto &i: v){
        cin>>i;
    }
        
    //Sliding window maximum
    multiset<int, greater<int>> s;
    std::vector<int> ans;
    for(int i = 0; i<k; i++){
        s.insert(v[i]);
    }
    
    ans.push_back(*s.begin());
    
    for(int i = k; i<n; i++){
        s.erase(s.lower_bound(v[i-k]));
        s.insert(v[i]);
        ans.push_back(*s.begin());
    }
    
    for(auto i: ans)
        std::cout << i << " ";
        
        
        
    return 0;
}

//Less OPTIMIZED APPROACH
// O(nlogn)
