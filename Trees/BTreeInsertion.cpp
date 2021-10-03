#include<iostream>

//BTreeNode
class BTreeNode{
  
  int t; //minm degree
  int *keys; //array of keys
  BTreeNode** C;//array of children of node;
  int n;//pointer to index of keys
  bool leaf; //if leaf node or not
  
  public:
  BTreeNode(int _t, bool _leaf); //constructor
  void traverse(); //traverse function
  BTreeNode* search(int k); //search function
  
  void insertNonFull(int k); //inserts key to node; assumption only if non full
  
  void splitChild(int i, BTreeNode* node); //splits node; assumption only if full; i is index of child
  
  friend class BTree;
    
};

//BTree 
class BTree{
    
    int t; //minm degree
    BTreeNode* root;
    
    public:
    //constructor
    BTree(int _t){
        t = _t; 
        root = NULL;
    }  
    //traverse function
    void traverse(){
        if(root) root->traverse();
    }
    
    //search function
    BTreeNode* search(int k){
        if(root) return root->search(k);
        
        return NULL;
    }
    
    //main insert function to insert key to BTree
    void insert(int key);
    
};

//BTreeNode constructor
BTreeNode::BTreeNode(int _t, bool _leaf){
    t = _t;
    leaf = _leaf;
    
    keys = new int[2*t -1]; //array of keys
    C = new BTreeNode*[2*t]; //array of children
    
    n = 0; //index of keys
}

//traverse function
void BTreeNode::traverse(){
    
    //traverse n keys and n children
    int i;
    for(i = 0; i<n; i++){
        if(!leaf) C[i]->traverse();
        std::cout<<" "<<keys[i];        
    }
    
    //traverse last child
    if(!leaf) C[i]->traverse();
}

//search function
BTreeNode* BTreeNode::search(int k){
    
    
    int i = 0;
    while(i<n && k>keys[i])
    i++;
    
    //if found
    if(keys[i] == k)
        return this;
        
    //if not found and end leaf reached
    if(leaf) return NULL;
    
    //else if children exist, search through them
    return C[i]->search(k);
}

//main insert function
void BTree::insert(int k){
    
    //if tree is NULL 
    if(!root){
        //create new node 
        root = new BTreeNode(t,true);
        root->keys[0] = k; //insert new key 
        root->n = 1; //update key count
        return;
    }
    //if not null  
    //check if root is full 
    if(root->n == 2*t -1){
        
        //create new node
        BTreeNode* s = new BTreeNode(t, false);
        //make root node child of new node 
        s->C[0] = root;
        
        //split root node and move 1 key to root
        s->splitChild(0, root);
        
        //now s has 2 children, decide where to insert new key 
        int i = 0;
        if(s->keys[i] < k)
            i++;
            
        //insert key in child    
        s->C[i]->insertNonFull(k);
        
        //change root 
        root = s;
    }
    //if not full, call insertNonFull on root
    else root->insertNonFull(k);
}


//insert on non full node function
void BTreeNode::insertNonFull(int k){
    
    //index of rightmost element
    int i = n-1;
    
    if(leaf){
    //find right location to insert key and right shift greater keys
    
    while(i>=0 && keys[i] > k){
        keys[i+1] = keys[i];
        i--;
    }
    
    //insert key
    keys[i+1] = k;
    n = n+1; //increment count of keys
    }
    //if not leaf, go to leaf 
    else{
        //finding right location
        while(i>=0 && keys[i] > k)
            i--;
            
        //if node is full, split node
        if(n == 2*t-1){
            splitChild(i+1, C[i+1]);
        
            //if keys[i+1] is less than k, increment i 
            if(keys[i+1] < k)
                i++;
        }
        
        C[i+1]->insertNonFull(k);   
    }
        
}

//split function 
void BTreeNode::splitChild(int i, BTreeNode* y){
    
    //i is index of child 
    BTreeNode *z = new BTreeNode(y->t, y->leaf);
    z->n = t-1; //count of keys in z
    
    //copy last t-1 keys in y to z
    for(int j = 0; j<t-1; j++)
        z->keys[j] = y->keys[j+t];
        
    //copy t children
    if(!y->leaf)
        for(int j = 0; j<t; j++)
            z->C[j] = y->C[j+t];
        
    y->n = t-1; //reducing count of keys in y 
    
    //create space to insert new child z in this node 
    for(int j = n; j>=i+1; j--)
        C[j+1] = C[j]; //right shift
        
    // insert z
    C[i+1] = z;
    
    //new key to be inserted in this node
    
    //1. right shift keys of this node to create space for new key 
    for(int j = n-1; j>=i; j--)
        keys[j+1] = keys[j];
        
    //copy mid key of y to this node 
    keys[i] = y->keys[t-1];
    
    //increment count of keys in this node
    n = n+1;
}

int main(){
    
    BTree root(3);
    root.insert(10);
    root.insert(20);
    root.insert(5);
    root.insert(6);
    root.insert(12);
    root.insert(30);
    root.insert(7);
    root.insert(17);
    
    std::cout << "Traversal of the constructed tree is ";
    root.traverse();
 
    int k = 6;
    (root.search(k) != NULL)? std::cout << "\nPresent" : std::cout << "\nNot Present";
 
    k = 15;
    (root.search(k) != NULL)? std::cout << "\nPresent" : std::cout << "\nNot Present";
    
    return 0;
}
