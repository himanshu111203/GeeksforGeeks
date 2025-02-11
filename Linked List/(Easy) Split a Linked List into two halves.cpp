class Solution {
  public:
    pair<Node *, Node *> splitList(struct Node *head) {
        if(head->next==head)
        return {head,head};
        Node *slow=head,*fast=head;
        while(fast->next!=head && fast->next->next!=head){
            slow=slow->next;
            fast=fast->next->next;
        }
        Node *second=slow->next;
        slow->next=head; //make first half circular
        Node *temp=second; // find last node of second hald and connect to first of it
        while(temp->next!=head)
        temp=temp->next;
        temp->next=second;
        return {head,second};
    }
};
