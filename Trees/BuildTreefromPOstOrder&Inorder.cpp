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

//buildTree from postOrder and inorder

node* buildTree(vector<int> postorder, vector<int> inorder, int start, int end){
    
    static int idx = postorder.size()-1;
    
    //base case 
    if(start>end){
        return NULL;
        
    }
    
    int curr = postorder[idx];
    idx--;
    node* Node = new node(curr);
    
    if(start == end){
        return Node;
    }
    
    int pos = search(inorder, start, end, curr);
    //first right subtree
    Node->right = buildTree(postorder, inorder, pos + 1, end);
    //left subtree
    Node->left = buildTree(postorder, inorder, start, pos-1);
    
    return Node;
}

int main(){
    
    vector<int> preorder = {1,2,4,3,5};
    vector<int> postorder = {4,2,5,3,1};
    vector<int> inorder = {4,2,1,5,3};
    
    node* root = buildTree(postorder, inorder, 0, (postorder.size()-1));
    
    inorderPrint(root);
    
    return 0;
}
