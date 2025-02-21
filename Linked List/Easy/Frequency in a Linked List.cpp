class Solution {
  public:
    int count(struct Node* head, int key) {
        int c=0;
        while(head)
        {
            
            if(head->data==key)
            c++;
            head=head->next;
        }
        return c;
    }
};
