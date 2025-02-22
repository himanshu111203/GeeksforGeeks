class Solution {
  public:
    Node *moveToFront(Node *head) {
        Node *curr=head,*prev=NULL;
        while(curr->next){
            if(curr->next)
            prev=curr;
            curr=curr->next;
        }
        prev->next=NULL;
        curr->next=head;
        return curr;
    }
};
