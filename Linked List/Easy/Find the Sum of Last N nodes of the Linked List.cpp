class Solution {
  public:
    /*Structure of the node of the linled list is as

    struct Node {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }
    };
    */
    // your task is to complete this function
    // function should return sum of last n nodes
    int sumOfLastN_Nodes(struct Node* head, int n) {
        int sum=0;
        int size=0;
        Node *temp=head;
        while(temp!=NULL)
        {
            sum+=temp->data;
            size++;
            temp=temp->next;
        }
        int a=size-n;
        temp=head;
        while(a--)
        {
            sum-=temp->data;
            temp=temp->next;
        }
        return sum;
    }
};
