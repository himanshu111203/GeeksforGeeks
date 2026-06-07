/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node *rev(Node *curr,Node *prev){
        if(!curr)
        return prev;
        Node *fut=curr->next;
        curr->next=prev;
        return rev(fut,curr);
    }
    Node *compute(Node *head) {
        // code here
        head=rev(head,NULL);
        int val=head->data;
        Node *temp=head->next,*prev=head;
        while(temp){
            while(temp && temp->data<val)
            temp=temp->next;
            prev->next=temp;
            prev=temp;
            if(prev)
            val=prev->data;
            if(temp)
            temp=temp->next;
        }
        return rev(head,NULL);
    }
};
