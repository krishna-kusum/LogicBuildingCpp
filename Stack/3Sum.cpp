//THREE SUM PROBLEM
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<utility>

using namespace std;

int main(){
    
    int n;
    cin>>n;
    int target;
    cin>>target;
    vector<int> a(n);    
    
    for(auto &i: a)
        cin>>i;
    
    bool res = false;
    //BRUTE FORCE APPROACH
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            for(int k = j+1; k<n; k++){
                if(a[i] + a[j] + a[k] == target){
                    res = true;
                    break;
                }
            }
        }
    }
    
    std::cout << res << std::endl;
    return 0;
}

//O(N^3)
