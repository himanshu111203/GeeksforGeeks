// divide in three part detach second part from first and third part, reverse it and then attach second part to the first and third
class Solution {
  public:
    Node* rev(Node *curr,Node *prev){  
        if(!curr)
        return prev;
        Node *fut=curr->next;
        curr->next=prev;
        return rev(fut,curr);
    }
    Node* reverseBetween(int a, int b, Node* head) {
        Node *prev=NULL,*curr=head;
        while(--a){
            prev=curr;
            curr=curr->next;
            --b;
        }
        //curr is the first node of second part
        if(prev) // if first part exist example if a=1 then there is no first part
        prev->next=NULL;
        Node *temp=curr,*nex=curr->next;
        while(--b){
            temp=nex;
            nex=nex->next;
        }
        //nex id first node of third part
        if(nex) // if third part present then only we have to detach second part, if b=5 and size of LL is 8 then there is no second part
        temp->next=NULL;
        curr=rev(curr,NULL); // reverse the second part
        temp=curr;
        while(temp->next)
        temp=temp->next;
        if(nex) // if third part exist attach last node of second part to it
        temp->next=nex;
        if(!prev) // if first part not exist then we return first node of second part curr
        return curr;
        prev->next=curr; //if first part exist then attach last node to send part
        return head; //return head
    }
};
