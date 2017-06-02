/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{
  // Complete this method
    if (head == NULL)
        return NULL;
    
    Node* curPos = head;
    if (position == 0){
        head = curPos->next;
        delete curPos;
        return head;
    }
    
    for (int i=0; i<position-1; i++){
        curPos=curPos->next;
    }
    
    Node* deleteMe = curPos->next;
    curPos->next = deleteMe->next;
    delete deleteMe;
    
    return head;
}