class Solution {
  public:

    Node* insertInEmptyList(Node* last, int data) {
        last=new Node(data);
        last->next=last;
        return last;
    }
};
