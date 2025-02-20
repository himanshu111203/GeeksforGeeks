class Solution {
  public:
    /* Function to delete a node from a linked list */
    Node* deleteNode(Node* head, int x) {
        Node *curr=head,*prev=NULL;
        if(x==1)
        return head->next;
        while(--x){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        delete curr;
        return head;
    }
};
