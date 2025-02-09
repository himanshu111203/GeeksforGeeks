class Solution {
  public:
  Node *rev(Node *curr,Node *prev){
      if(!curr)
      return prev;
      Node *fut=curr->next;
      curr->next=prev;
      return rev(fut,curr);
  }
    struct Node* modifyTheList(struct Node* head) {
        Node *temp=new Node(0);
        Node *del=temp;
        Node *curr=head;
        while(curr){
            temp->next=new Node(curr->data);
            temp=temp->next;
            curr=curr->next;
        }
        temp=del->next;
        delete del;
        temp=rev(temp,NULL);
        Node *sh=head,*slow=temp,*fast=temp;
        while(fast->next && fast->next->next){
            slow->data-=sh->data;
            sh=sh->next;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast->next && !fast->next->next)
        slow->data-=sh->data;
        return temp;
    }
};