
 #include<iostream>
 #include<vector>
 #include<queue>
 #include<algorithm>
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
 //HEIGHT OF BINARY TREE
 
 int height(node* root){
     
     //if NULL
     if(root == NULL){
         return 0;
     }
     
     int lheight = height(root->left); //height of left subtree
     int rheight = height(root->right); //height of right subtree
     
     return max(lheight, rheight) + 1;
 }
 
 
 int main(){
     
     node* root = new node(1);
     root->left = new node(2);
     root->right = new node(3);
     root->left->left = new node(4);
     root->left->right = new node(5);
     root->right->left = new node(6);
     root->right->right = new node(7);
     
     std::cout << height(root) << std::endl;
     
     
     return 0;
 }
