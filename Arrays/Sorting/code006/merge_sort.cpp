#include<iostream>

//swap
void swap(int *x, int *y){
    
    int temp = *x;
    *x = *y;
    *y = temp;
}

void merge(int *arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int L[n1], R[n2];
    
    //left array
    for(int i = 0; i<n1; i++){
        
        L[i] = arr[left + i]; 
    }
    //right array
    for(int i = 0; i<n2; i++){
        
        R[i] = arr[mid + 1 + i]; 
    }
    
    
    //filling the sorted array
    int i =0, j= 0;
    int k = left;
    
    while(i<n1 && j<n2 && k <= right){
        if(L[i] < R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        
        k++;
    }
    
    //if L has elements
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    
    //if R has elements
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}


//merge sort
void mergeSort(int* arr, int left, int right){
    
    if(left < right){
        int mid = (left+ right)/2;
        
        mergeSort(arr, left, mid);//divide
        mergeSort(arr, mid + 1, right);//conquer
        merge(arr, left, mid, right); //combine
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
    
    mergeSort(arr, 0, n-1);
    display(arr, n);
   
   
   return 0;
}

//Time complexity : O(nlogn)
//space complexity : O(n)
