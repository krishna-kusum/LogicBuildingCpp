#include<iostream>

//insertion sort
void inserionSort(int* arr, int n){
    
    int target;
    for(int i = 1; i<n; i++){
        
        int target = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > target){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = target;
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
    
    inserionSort(arr, n);
    display(arr, n);
   
   
   return 0;
}

//Time complexity : O(n^2)
//space complexity: O(1)
