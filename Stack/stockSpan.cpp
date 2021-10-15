//STOCK SPAN PROBLEM
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int main(){
    
    vector<int> a = {100,80,60,70,65,70,85};
    vector<int> days;
    
    int n = a.size();
    
    //BRUTE FORCE APPROACH
    
    for(int i = 0; i<n; i++){
        int count = 0;
        for(int j = i; j>=0; j--){
            if(a[j]<=a[i])
                count++;
            else
                break;
        }
        days.push_back(count);
    }
    
    for(auto i: days)
        cout<<i<<" ";
    
    return 0;
}
