/*
    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* SortedInsert(Node *head,int data)
{
    // Complete this function
   // Do not write the main method. 
    Node* newN = new Node;
    if (newN==NULL) return head;
    newN->data = data;
    newN->next = NULL;
    newN->prev = NULL;
    // special case for the head
    if (head == NULL) {
        head = newN;        
        return head;
    }
    if (data <= head->data) {
        newN->next = head;
        head->prev = newN;
        head = newN;
        return head;
    }
    Node *curr = head;
    while (curr->next) {
        if (data <= curr->data) {
            newN->prev = curr->prev;
            newN->next = curr;
            curr->prev->next = newN;
            curr->prev = newN;
            
            return head;
        }
        curr = curr->next;
    }
    
    if (data <= curr->data) {
        newN->prev = curr->prev;
        newN->next = curr;
        curr->prev->next = newN;
        curr->prev = newN;
    }
    else {
        curr->next = newN;
        newN->prev = curr;
    }     
    return head;
}
