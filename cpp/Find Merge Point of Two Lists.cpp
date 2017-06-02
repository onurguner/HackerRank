/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
int FindMergeNode(Node *headA, Node *headB)
{
    // Complete this function
    // Do not write the main method. 
    while (headA){
        Node *loop=headB;
        while (loop) {
            if (headA==loop) {
                return headA->data;
            }                
            loop=loop->next;
        }        
        headA=headA->next;
    }        
    return 0;
}