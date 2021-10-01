#include<iostream>

struct node{
    int data;
    struct node* left;
    struct node* right;
    node(int val){
        data = val;
        left = right = NULL;
    }
};

//insert function
struct node* insert(struct node* root,int val){
    //if empty
    if(!root){
        return new node(val);
    }
    
    //if val < root->data; insert in left subtree
    if(val < root->data){
        root->left = insert(root->left, val);
    }else {
        root->right = insert(root->right, val);
    }
    
    //return node after insertion
    return root;
}

//minimum value in a tree 
struct node* minValTree(struct node* root){
    
    //if root is NULL
    if(!root){
        return NULL;
    }
    
    struct node* curr = root;
    
    //else traverse to leftmost node
    while(curr && curr->left){
        curr = curr->left;    
    }
    
    return curr;
}


//deletion operation
struct node* deleteNode(struct node* root, int val){
    
    //if empty 
    if(!root){
        return NULL;
    }//if val greater; search through right subtree
    
    if(val > root->data){
        root->right = deleteNode(root->right, val);
    }//if val less; search through left subtree
    
    else if(val < root->data){
        root->left = deleteNode(root->left, val);
    }
    //else if val equals root->data
    else{
        
        //if no child
        if(!root->left && !root->right ){
            return NULL;
        }
        //if one child present
        else if(!root->left){
            struct node* temp = root->right;
            free(root);
            
            return temp;
        }
        else if(!root->right){
            struct node* temp = root->left;
            free(root);
            
            return temp;
        }
        //if both children present
        else{
            //find inorder successor
            struct node* temp = minValTree(root->right);
            
            root->data = temp->data;
            
            //delete minVal node
            root->right = deleteNode(root->right, temp->data);
        }
    }
    
    //return node after deletion
    return root;
}

//inorder traversal
void inorder(struct node* root){
    
    if(root ==  NULL){
        return;
    }
    
    //left subtree traversal
    inorder(root->left);
    
    //print data
    std::cout<<root->data<<" ";
    
    //right subtree traversal
    inorder(root->right);
}

//driver function
int main(){
    
    struct node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    
    inorder(root);
    
    std::cout<<"\n";
    root = deleteNode(root,20);
    inorder(root);
    
    std::cout<<"\n";
    root = deleteNode(root,70);
    inorder(root);
    
    return 0;
    
}
