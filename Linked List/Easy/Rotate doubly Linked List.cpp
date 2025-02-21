class Solution {
public:
    Node *rotateDLL(Node *start,int p)
    {
        Node *temp=start;
        while(p--)
        temp=temp->next;
        temp->prev->next=NULL;
        temp->prev=NULL;
        Node *t=temp;
        while(t->next!=NULL)
        t=t->next;
        t->next=start;
        return temp;
    }
};
