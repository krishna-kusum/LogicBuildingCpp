//BRUTE FORCE APPROACH
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int rainWaterTrapped(vector<int> a, int n){
    int ans = 0;
    int left, right;
    for(int i = 0; i<n; i++){
        
        //left max
        left = a[i];
        for(int j = 0; j<i; j++)
            left = max(left, a[j]);
            
        //right max
        right = a[i];
        for(int j = i+1; j<n; j++)
            right = max(right, a[j]);
            
        //calculate sum block
        ans += max(min(left,right)-a[i], 0);
    }
    
    return ans;
        
}

int main(){
    
    int n;
    cin>>n;
    vector<int> a(n);
    
    for(auto &i : a)
        cin>>i;
        
    // vector<int> a = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    // int n = a.size();
    
    cout<<rainWaterTrapped(a,n);
    
    return 0;
}
