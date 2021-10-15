 //MAX CONSECUTIVE ONES
 
 #include<iostream>
 #include<vector>
 #include<algorithm>
 
 using namespace std;
 int main(){
    
    int n;
    cin>>n;
    int k;cin>>k;
    
    std::vector<int> a(n);
    
    for(auto &i : a)
        cin>>i;
        
    //Using 2 Pointers
    
    int zero_count = 0, i = 0;//left window
    int ans = 0;
    //j -> right window
    for(int j = 0; j<n; j++){
        
        if(a[j] == 0)
            zero_count++;
        while(zero_count> k){
            if(a[i] == 0)
                zero_count--;
            i++;
        }
        
        //zero_count <= k 
        ans = max(ans, j-i +1);
    }
    
    cout<<ans;
     
     return 0;
 }
 
 //5 2 
 //1 1 0 0 1 
 //O(n)
