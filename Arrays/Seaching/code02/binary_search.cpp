#include<iostream>

int recur_idx(int arr[], int left, int right, int k){
    
    //base if not found
    if(left > right){
        return -1;
    }
    
    //base condition
    int mid = (left + right)/2;
    if(arr[mid] == k){
        return mid;
    }
    
    if(arr[mid] > k){
        right = mid-1;
    }else if(arr[mid] < k){
        left = mid+1;
    }
    
    return recur_idx(arr, left, right, k);
    
}

int main(){
    
    int n;
    std::cin>>n; //size
    
    int arr[n];
    for(int i = 0; i<n; i++){
        std::cin>>arr[i];
    }
    
    int k;
    std::cin>>k; //searching element
    
    //sorting the array
    for(int i = 0 ; i<n-1; i++){
        for(int j = i+1; j<n; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
   std::cout<<recur_idx(arr,0, n-1, k);
   
   return 0;
}

//Time complexity : O(Logn)
