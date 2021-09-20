#include<iostream>
//bubble sort

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

//bubble sort
void bubbleSort(int *arr, int n){
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n-1-i; j++ ){
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
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
    
    bubbleSort(arr, n);
    display(arr, n);
   
   
   return 0;
}

//Time complexity : O(n^2)
