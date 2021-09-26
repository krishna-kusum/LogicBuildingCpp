#include<iostream>
#include<climits>

void sortArray(int* arr, int n){
    
    for(int i = 0; i<n-1; i++){
        for(int j = i; j<n; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    for(int i = 0; i<n; i++)
        std::cout<<arr[i]<<" ";
    
}

int findMaxElement(int* arr1, int n1, int* arr2, int n2){
    
    int max1 = INT_MIN, max2 = INT_MIN;
    
    for(int i = 0; i<n1; i++)
        if(max1 < arr1[i])
            max1 = arr1[i];
            
    for(int i = 0; i<n2; i++)
        if(max2<arr2[i])
            max2 = arr2[i];
            
    std::cout<<"\n"<<max1<<" "<<max2<<"\n";
    
    return std::max(max1, max2);
}

int main(){
    int x;
    std::cin>>x;
    int arr1[x];
    int i;
    
    for(i = 0; i<x; i++)
        std::cin>>arr1[i];
    
    int y;
    std::cin>>y;
    int arr2[y];
    for(i = 0; i< y; i++)
        std::cin>>arr2[i];
        
    sortArray(arr1,x);
    
    std::cout<<"\n"<<findMaxElement(arr1, x, arr2, y);
    
    return 0;
}
