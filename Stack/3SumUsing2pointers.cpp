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
   
   //Two Pointer Approach//Two Sum Approach
   sort(a.begin(), a.end());
   
   for(int i = 0; i<n; i++){
       int lo = i+1, hi = n-1; //two pointer 
       while(lo<hi){
           int currSum = a[i] + a[lo] + a[hi];
           if(currSum == target){
               res = true;
               break;
           }else if(currSum<target)
                lo++;
            else
                hi--;
                
       }
   }
   
    std::cout << res << std::endl;
    return 0;
}

//n = 6 
//target = 24
//1 3 6 7 9 12

//O(N^2)
