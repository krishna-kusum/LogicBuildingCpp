//PRINT NODES AT K DISTANCE

#include<iostream>
#include<vector>

using namespace std;

class node{
    public:
    int data;
    node* left,*right;
    
    node(int val){
        data = val;
        left = right = NULL;
    }
};

//CASE 1 
void printSubtreeNodes(node* root, int k){
    if(root == NULL || k <0){
        return;
    }
    
    if(k == 0){
        std::cout << root->data << " ";
        return;
    }
    
    printSubtreeNodes(root->left, k-1);
    printSubtreeNodes(root->right, k-1);
}

//CASE 2 
int printNodesAtK(node* root, node* target, int k){
    
    if(root == NULL){
        return -1;
    }
    
    if(root == target){
        printSubtreeNodes(root, k);
        return 0;
    }
    
    //search for target in left subtree 
    int dl = printNodesAtK(root->left, target, k);
    if(dl != -1){
        
        if(dl + 1 == k){
            cout<<root->data<<" ";
            
        }else{
            printSubtreeNodes(root->right, k-dl-2);
        }
        return dl +1;
    }
    
    //search for target in right subtree 
    int dr = printNodesAtK(root->right, target, k);
    if(dr != -1){
        
        if(dr + 1 == k){
            cout<<root->data<<" ";
            
        }else{
            printSubtreeNodes(root->left, k-dr-2);
        }
        return dr +1;
    }
    
    return -1;
}

int main(){
  
  node* root = new node(1);
  root->left = new node(5);
  root->right = new node(2);
  root->right->left = new node(3);
  root->right->right = new node(4);
  root->left->left = new node(6);
  root->left->left->right = new node(7);
  root->left->left->right->left = new node(8);
  root->left->left->right->right = new node(9);
    
    printNodesAtK(root, root->left,3);
    
    return 0;
}
