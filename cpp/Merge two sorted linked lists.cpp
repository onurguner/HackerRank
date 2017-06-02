/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
    if (headA == NULL && headB == NULL) return NULL;
    if (headA == NULL) return headB;
    if (headB == NULL) return headA;
    
    Node *head = NULL;
    Node *prev = NULL;
    while (headA && headB) {
        if (head == NULL) {
            if (headA->data <= headB->data) {
                head = headA;
                prev = headA;
                headA = headA->next;
            }
            else {
                head = headB;
                prev = headB;
                headB = headB->next;
            }
        }
        else {
            if (headA->data <= headB->data) {
                prev->next = headA;
                prev = headA;
                headA = headA->next;
            }
            else {
                prev->next = headB;
                prev = headB;
                headB = headB->next;         
            }
        }            
    }
    if (headA) {
        prev->next = headA;
    }
    else if (headB) {
        prev->next = headB;
    }
    return head;
}