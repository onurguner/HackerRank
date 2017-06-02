/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/


void decode_huff(node * root,string s)
{
    if (root == NULL)
        return;
    
    string decoded;
    node* temp = root;
    for (int nIndex=0; nIndex < s.length(); nIndex++) {
        
        if (s[nIndex] == '0') {
            temp = temp->left;
        }
        else if (s[nIndex] == '1') {
           temp = temp->right;
        }
        
        if (temp->left == NULL && temp->right==NULL) {
            decoded += temp->data;
            temp = root;
        }
    }
    printf("%s", decoded.c_str());
}