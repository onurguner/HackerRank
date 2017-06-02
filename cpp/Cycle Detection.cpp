/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    if (head == NULL) 
        return false;
    
    Node *slow = head;
    Node *fast = head;
    while (true) {        
        slow = slow->next;
        fast = fast->next->next;
                
        if (fast == NULL)
            return false;
        else if (fast == slow || fast->next==slow)
            return true;
    }
}