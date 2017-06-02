/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* Reverse(Node* head)
{
    // Complete this function
    // Do not write the main method. 
    if (head==NULL) return NULL;
    
    Node *next = NULL;
    Node *cursor = head;
    while (cursor){
        next=cursor->next;
        
        cursor->next = cursor->prev;
        cursor->prev = next;
        
        if (next == NULL)
            return cursor;
        else
            cursor = next;
    }
    return NULL;
}
