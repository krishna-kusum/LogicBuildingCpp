#include<iostream>

class BST{
    int data;
    struct BST* left;
    struct BST* right;
    
    public:
    BST();//default constructor
    BST(int); //parmameterized constructor
    BST* insert(BST*,int);//insert function
    void inorder(BST*);//inorder traversal
};

//default constructor
BST::BST():data(0),left(NULL),right(NULL){}

//parameterized constructor
BST::BST(int val){
    data = val;
    left = right = NULL;
}

//insert function
BST* BST::insert(BST* root, int val){
    
    //if empty or leafnode
    if(!root){
        //insert 1st node
        return new BST(val);
    }
    //insert data
    //if val>root->data; insert in right subtree
    if(val>root->data){
        root->right = insert(root->right, val);
    }//else insert in left subtree
    else{
        root->left = insert(root->left, val);
    }
    
    //return node after insertion
    return root;
}

//inorder traversal
void BST::inorder(BST* root){
    //if empty, return
    if(!root){
        return;
    }
    
    //traverse left subtree
    inorder(root->left);
    //print root data
    std::cout<<root->data<<" ";
    //traverse right subtree
    inorder(root->right);
}

//inorder traversal
int main(){
    BST b, *root = NULL;
    root = b.insert(root, 50);
    b.insert(root, 30);
    b.insert(root, 20);
    b.insert(root, 40);
    b.insert(root, 70);
    b.insert(root, 60);
    b.insert(root, 80);
    
    b.inorder(root);
    
    return 0;
}
