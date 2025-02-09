class Solution {
  public:
  Node* rev(Node *curr,Node *prev){
      if(!curr)
      return prev;
      Node *fut=curr->next;
      curr->next=prev;
      return rev(fut,curr);
  }
    void reorderList(Node* head) {
        if(!head || !head->next)
        return;
        Node *slow=head,*fast=head,*pre=NULL;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        Node *head1=head,*head2=slow->next;
        slow->next=NULL;
        head2=rev(head2,NULL);
        while(head2 && head1){
            Node *nex1=head1->next,*nex2=head2->next;
            head1->next=head2;
            head2->next=nex1;
            head1=nex1;
            head2=nex2;
        }
        return;
    }
};
