/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Insert(Node *head,int data)
{
  // Complete this method
    Node* newElem = new Node;
    if (newElem == NULL)
        return NULL;
    
    newElem->data = data;
    newElem->next = NULL;
    
    if (head == NULL) {
        head = newElem;    
        return head;
    }
    
    Node* curPos = head;
    while (curPos) {
        if (curPos->next == NULL) {
            curPos->next = newElem;
            return head;
        }
        curPos = curPos->next;
    }
    
    return NULL;
}