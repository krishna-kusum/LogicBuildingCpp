//STOCK SPAN PROBLEM
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<utility>

using namespace std;

vector<int> stockSpan(vector<int> prices){
    
    vector<int> ans;
    stack<pair<int,int>> st;
    
    for(auto price : prices){
        int days = 1;
        while(!st.empty() && st.top().first <= price){
            days += st.top().second;
            st.pop();
        }
        st.push(make_pair(price,days));
        ans.push_back(days);
    }
    
    return ans;
}

int main(){
    
    vector<int> a = {100,80,60,70,65,70,85};
    vector<int> ans = stockSpan(a);
    
    
    
    for(auto i: ans)
        cout<<i<<" ";
    
    return 0;
}
