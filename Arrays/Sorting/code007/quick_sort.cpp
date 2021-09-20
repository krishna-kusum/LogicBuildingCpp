#include<iostream>

//swap
void swap(int *x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

//partition
int partition(int* arr, int low, int high){
    
    int pivot = arr[high];
    int swapIdx = low - 1;
    
    for(int i = low; i<=high-1; i++){
        if(arr[i]<pivot){
            swapIdx++;
            swap(&arr[swapIdx], &arr[i]);
        }
        
    }
    
    swap(&arr[swapIdx + 1], &arr[high]);
    
    return swapIdx + 1;
}


//quickSort
void quickSort(int* arr, int low, int high){
    
    if(low < high){
        
        int pivotIdx = partition(arr, low, high);
        
        quickSort(arr, low, pivotIdx-1);
        quickSort(arr, pivotIdx+1, high);
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
    
    quickSort(arr, 0, n-1);
    display(arr, n);
   
   return 0;
}

//Time complexity : O(nlogn)
//space complexity : O(1)
