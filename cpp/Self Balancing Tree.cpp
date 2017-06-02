/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */

node * getNewNode(int val) {
    node* newNode = new node();
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->ht = 0;
    return newNode;
}

int getMax(int x, int y) {
    return (x > y) ? x : y;
}

int getHeight(node* root) {
    if (root == NULL)
        return -1;
    return root->ht;
}

int setHeight(node* root) {
    return getMax(getHeight(root->left), getHeight(root->right)) + 1;
}

int getBalanceFactor(node* root) {
    if (root == NULL)
        return 0;
    return (getHeight(root->left) - getHeight(root->right));    
}

node * rotateLeft(node* root) {
    node* newRoot = root->right;
    // perform rotation
    root->right = newRoot->left;
    newRoot->left = root;
    // update heights
    root->ht = setHeight(root);
    newRoot->ht = setHeight(newRoot);
    // return new root
    return newRoot;
}

node * rotateRight(node* root) {
    node* newRoot = root->left;
    // perform rotation
    root->left = newRoot->right;
    newRoot->right = root;
    // update heights
    root->ht = setHeight(root);
    newRoot->ht = setHeight(newRoot);
    // return new root
    return newRoot;
}

node * insert(node * root,int val)
{
    // perform insertion
    if (root == NULL) {
        root = getNewNode(val);        
    }
    else if (val < root->val) {
        root->left = insert(root->left, val);
    }
    else if (val > root->val) {
        root->right = insert(root->right, val);        
    }
    // update height of this node
    root->ht = setHeight(root);
    // check balance    
    int nBalanceFactor = getBalanceFactor(root); 
    // 1. left-right
    if (nBalanceFactor > 1 && val > root->left->val) {
        root->left = rotateLeft(root->left);
        root = rotateRight(root);
    }
    // 2. left-left
    else if (nBalanceFactor > 1 && val < root->left->val) {
         root = rotateRight(root);
    }
    // 3. right-left
    else if (nBalanceFactor < -1 && val < root->right->val) {
        root->right = rotateRight(root->right);
        root = rotateLeft(root);
    }
    // 4. right-right
    else if (nBalanceFactor < -1 && val > root->right->val) {
         root = rotateLeft(root);
    }
    
    return root;
}