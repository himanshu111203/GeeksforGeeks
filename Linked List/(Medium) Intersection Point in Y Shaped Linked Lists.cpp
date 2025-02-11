class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        int a=0,b=0;
        Node *temp=head1;
        while(temp){
            a++;
            temp=temp->next;
        }
        temp=head2;
        while(temp){
            b++;
            temp=temp->next;
        }
        while(a>b){
            head1=head1->next;
            a--;
        }
        while(b>a){
            head2=head2->next;
            b--;
        }
        while(head1!=head2){
            head1=head1->next;
            head2=head2->next;
        }
        Node *ans=new Node(-1);
        if(!head1)
        return ans;
        return head1;
    }
};
