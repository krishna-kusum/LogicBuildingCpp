#include<iostream>
#include<string>
#include<vector>
using namespace std;

class node{
    
    public:
    int data;
     node* left;
     node* right;
    
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorderPrint( node* root){
    
    //base
    if(root == NULL)
        return;
        
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

//search function to return index
int search(vector<int> inorder, int start, int end, int data){
    
    for(int i = start; i<=end; i++)
    {
        if(inorder[i] == data){
            return i;
        }
    }
    
    return -1;
}

// buildTree function

node* buildTree(std::vector<int> preorder, vector<int> inorder, int start, int end){
    
    static int idx = 0; //to store index of preorder 
    
    //base condition
    if(start > end){
        return NULL;
    }
    
    node* Node = new node(preorder[idx]);
    idx++;
    
    //if only 1 node left
    if(start == end){
        return Node;
    }
    
    //position of preorder[idx] in inorder
    int pos = search(inorder, start, end, preorder[idx-1]);
    Node->left = buildTree(preorder, inorder, start, pos-1);
    Node->right = buildTree(preorder,inorder, pos+1, end);
    
    return Node;
}

int main(){
    
    vector<int> preorder = {1,2,4,3,5};
    vector<int> inorder = {4,2,1,5,3};
    
    node* root = buildTree(preorder, inorder, 0, preorder.size()-1);
    
    inorderPrint(root);
    
    return 0;
}
