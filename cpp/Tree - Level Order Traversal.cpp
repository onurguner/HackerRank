
/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

#include <queue>
using namespace std;

void LevelOrder(node * root)
{
    if (root == NULL)
        return;
    
    std::queue<node*> qNodes;  
    qNodes.push(root);
    while(!qNodes.empty()) {
        node* temp = qNodes.front();        
        printf("%d ", temp->data);
        if (temp->left != NULL)
            qNodes.push(temp->left);
        if (temp->right != NULL)
            qNodes.push(temp->right);
            
        qNodes.pop();
    }  
}