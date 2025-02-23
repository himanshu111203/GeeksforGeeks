class Solution {
  public:
  Node* reverse(Node *curr,Node *prev){
      if(curr==NULL)
      return prev;
      Node *fut=curr->next;
      curr->next=prev;
      return reverse(fut,curr);
  }
    Node* addTwoLists(Node* num1, Node* num2) {
        num1=reverse(num1,NULL);
        num2=reverse(num2,NULL);
        Node *head=new Node(0);
        Node *tail=head;
        int carry=0,sum;
        while(num1 && num2){
            sum=num1->data+num2->data+carry;
            tail->next=new Node(sum%10);
            carry=sum/10;
            tail=tail->next;
            num1=num1->next;
            num2=num2->next;
        }
        while(num1){
            sum=num1->data+carry;
            tail->next=new Node(sum%10);
            carry=sum/10;
            tail=tail->next;
            num1=num1->next;
        }
        while(num2){
            sum=num2->data+carry;
            tail->next=new Node(sum%10);
            carry=sum/10;
            tail=tail->next;
            num2=num2->next;
        }
        while(carry){
            tail->next=new Node(carry%10);
            tail=tail->next;
            carry/=10;
        }
        head=reverse(head->next,NULL);
        //to avoid zero in starting
        while(!head->data)
        head=head->next;
        return head;
    }
};
