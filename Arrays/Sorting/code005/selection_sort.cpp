#include<iostream>

//swap
void swap(int *x, int *y){
    
    int temp = *x;
    *x = *y;
    *y = temp;
}

//selection sort
void selectionSort(int* arr, int n){
    
    for(int i = 0; i<n-1; i++){
        for(int j = i+1; j <n; j++){
            if(arr[i] > arr[j])
                swap(&arr[i], &arr[j]);
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
    
    selectionSort(arr, n);
    display(arr, n);
   
   
   return 0;
}

//Time complexity : O(n^2)
//space complexity : O(1)
