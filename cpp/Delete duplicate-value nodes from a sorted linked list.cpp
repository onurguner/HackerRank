/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
    if (head == NULL || head->next==NULL) return head;
    
    Node *prev = head;
    Node *curPos = head->next;
    
    while (curPos) {
        if (curPos->data == prev->data) {
            prev->next = curPos->next;
            curPos = curPos->next;
        } else {
            prev = curPos;
            curPos = curPos->next;
        }            
    }
    
    return head;
}