/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/
node* getNewNode(int x)
{
    node* newNode = new node;
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node * insert(node * root, int value)
{
   if (root == NULL) {
       root = getNewNode(value);       
   }
   else if (value < root->data) {
       root->left = insert(root->left, value);
   }
   else if (value > root->data) {
       root->right = insert(root->right, value);
   }
    return root;
    
}