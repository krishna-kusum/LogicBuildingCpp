#include<iostream>

int main(){
    
    int n;
    std::cin>>n; //size
    
    int arr[n];
    for(int i = 0; i<n; i++){
        std::cin>>arr[i];
    }
    
    int k;
    std::cin>>k; //searching element
    
    int idx = -1;
    
    for(int i = 0; i<n; i++){
        if(arr[i] == k){
            idx = i;
            break;
            //store pos of element in array
        }
    }
    
    std::cout<<idx;
    
    return 0;
}
