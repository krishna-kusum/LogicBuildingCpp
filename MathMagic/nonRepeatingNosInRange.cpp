#include<iostream>
#include<vector>

int main(){
    
    //taking inputs    
    int n1, n2;
    std::cin>>n1>>n2;
    
    //storing ans 
    int count = 0;
    
    //traversing n1 to n2
    for(int i = n1; i<=n2; i++){
                
        int num = i;
        std::vector<bool> visited;
        visited.assign(10, false);
        
        while(num>0){
            
            //if already visited
            if(visited[num%10] == true)
                break;
                
            //mark as visited
            visited[num%10] = true;
            num/=10;
        }
        
        if(!(num>0)){
            count++;
        }
        
        
    }   
    
    std::cout<<count;
    return 0;
}
