//Largest Rectangle Histogram
#include<iostream>
#include<vector>

using namespace std;

int main(){
    
    int n;
    cin>>n;
    vector<int> a(n);
    
    for(auto &i: a)
        cin>>i;
    
        
    //Brute Force Approach
    int ans = 0;
    
    for(int i = 0; i<n; i++){
        int minm = a[i];
        for(int j = i; j<n; j++){
            minm = min(a[j], minm);
            int width = j-i+1;
            ans = max(ans, width*(minm));
        }
    }
    
    std::cout << ans << std::endl;
    
    return 0;
}
