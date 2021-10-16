//LEVEL ORDER TRAVERSAL USING QUEUE
//SUM AT KTH LEVEL

 #include<iostream>
 #include<vector>
 #include<queue>
 
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
 
 void printLevelOrder(node* root){
     
     if(root==NULL){
         return;
     }
     
     //1st level 
     queue<node*> q;
     q.push(root);
     q.push(NULL);
     
     while(!q.empty()){
         
         node* node = q.front();
         q.pop();
         
         if(node != NULL){
             
             std::cout << node->data << " ";
             if(node->left)
                q.push(node->left);
            
            if(node->right)
                q.push(node->right);
         }else if(!q.empty()){
             q.push(NULL);
         }
         
     }
     
 }
 
 //SUM AT KTH LEVEL 
 
 int sumAtLevelK(node* root, int k){
 
 
    if(root== NULL){
        return -1;
    }    
    
    
     queue<node*> q;
     q.push(root);
     q.push(NULL);
     
     int level = 0;
     int sum = 0;
     
     while(!q.empty()){
         
         node* Node = q.front();
         q.pop();
         
         if(Node != NULL){
             
             if(level == k){
                 sum += Node->data;
             }
             
             if(Node->left)
                q.push(Node->left);
                
            if(Node->right)
                q.push(Node->right);
         }else if(!q.empty()){
             q.push(NULL);
             level++;
         }
     }
     
     return sum;
 }
 
 int main(){
     
     node* root = new node(1);
     root->left = new node(2);
     root->right = new node(3);
     root->left->left = new node(4);
     root->left->right = new node(5);
     root->right->left = new node(6);
     root->right->right = new node(7);
     
    //  printLevelOrder(root);
     
     cout<<sumAtLevelK(root,2);
     
     return 0;
 }
