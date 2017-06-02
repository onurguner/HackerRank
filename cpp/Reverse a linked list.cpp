/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head)
{
  // Complete this method
    if (head == NULL) return NULL;
    
    Node *cursor = NULL;
    Node *next = NULL;
    while (head){
        next = head->next;
        
        head->next = cursor;
        cursor = head;
        
        head = next;
    }
    
    return cursor;
}
