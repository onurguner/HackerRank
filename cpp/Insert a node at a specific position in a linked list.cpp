/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{
  // Complete this method only
  // Do not write main function. 
    Node *n = new Node;
    if (n==NULL) return head;
    n->next = NULL;
    n->data = data;
    
    if (head == NULL || position == 0) {
        n->next = head;
        head = n;
        return head;
    }
   
    Node *curr = head;
    for (int i=1; i<position; i++) {
        curr = curr->next;
    }
    
    n->next = curr->next;
    curr->next = n;
    
    return head;
}