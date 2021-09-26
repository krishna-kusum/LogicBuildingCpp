#include<iostream>
#include<climits>

struct item{
    
    int value;
    int priority;
    
};

//declaring array
item pr[1000000];

//size pointer pointing to last index
int size = -1;

void enqueue(int val, int priority){
    
    //if full
    if(size == 1000000){
        std::cout<<"Queue is full.";
        return;
    }
    size++;
    
    pr[size].value = val;
    pr[size].priority = priority;
}

//peek
int peek(){
    
    int highestPriority = INT_MIN;
    int ind = -1;
    
    for(int i = 0; i<=size; i++){
        
        //if same priority than greater value
        if(highestPriority == pr[i].priority && ind>-1 && pr[ind].value < pr[i].value){
            highestPriority = pr[i].priority;
            ind = i;
            
        }//else greater priority
        else if(highestPriority < pr[i].priority){
            highestPriority = pr[i].priority;
            ind = i;
        }
    }
    
    return ind;
}

//dequque
void dequque(){
    
    //index of highestPriority
    int ind = peek();
    
    for(int i = ind; i<size; i++)
        pr[i] = pr[i+1]; //left shifting
        
    size--;
}


int main(){
    
    enqueue(10,2);
    enqueue(14,4);
    enqueue(13,4);
    enqueue(16,3);
    enqueue(11,2);
    
    std::cout<<pr[peek()].value<<" ";
    dequque();
    
    std::cout<<pr[peek()].value<<" ";
    dequque();
    
    std::cout<<pr[peek()].value<<" ";
    dequque();
    
    std::cout<<pr[peek()].value<<" ";
    dequque();
    
    std::cout<<pr[peek()].value<<" ";
    
    return 0;
}
