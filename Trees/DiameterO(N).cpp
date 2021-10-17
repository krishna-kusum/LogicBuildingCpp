//DIAMETER OF A TREE


#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    
    node(int val){
        
        data = val;
        left = right = NULL;
    }
};
//DIAMETER OF TREE

int diameter(node* root, int*  height){
    
    //base case
    if(root == NULL){
        *height = 0;
        return 0;
    }
    
    int lh = 0, rh = 0;
    
    int ldiameter = diameter(root->left, &lh);
    int rdiameter = diameter(root->right, &rh);
    
    int currDiameter = lh + rh + 1;
    *height = max(lh, rh) + 1;
    
    return max(currDiameter, max(ldiameter, rdiameter));
}

int main(){
    
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    
    int height = 0;
    
    std::cout << diameter(root,&height);
    
    return 0;
}
//O(N)
