#include<iostream>

//swap
void swap(int *x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

//heapifydown
void heapify(int *arr, int n, int i){
    
    int max_idx = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    if(l<n && arr[l] > arr[max_idx])
        max_idx = l;
        
    if(r<n && arr[r] > arr[max_idx])
        max_idx = r;
        
    if(max_idx != i){
        swap(&arr[i], &arr[max_idx]);
        heapify(arr, n, max_idx);
    }
}

//heapSort
void heapSort(int *arr, int n){
    
    //last non leaf node
    for(int i = n/2 -1; i>=0; i--){
        heapify(arr, n, i);
    }
    
    //algo of exchanging last with max
    for(int i = n-1; i>=0; i--){
        swap(&arr[i], &arr[0]);
        heapify(arr, i, 0);
    }
    
}
//display array
void display(int *arr, int n){
    
    for(int i= 0; i<n; i++){
        std::cout<<*(arr + i)<<" ";
    }
}

int main(){
    
    int n;
    std::cin>>n; //size
    
    int arr[n];
    for(int i = 0; i<n; i++){
        std::cin>>arr[i];
    }
    
    heapSort(arr, n);
    display(arr, n);
   
   return 0;
}

//Time complexity : O(nlogn)
//space complexity : O(1)
