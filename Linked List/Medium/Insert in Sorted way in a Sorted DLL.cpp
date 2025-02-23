class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        Node* newn = getNode(x); 
        if (head == nullptr) {
            return newn; 
        }

        if (head->data >= x) {
            newn->next = head;
            head->prev = newn; 
            return newn; 
        }
        Node* curr = head;
        Node* front = head;

        while (front != nullptr ) {
            if (front->data >= x ) {
                curr->next = newn; 
                newn->prev = curr; 
                newn->next = front; 
                front->prev = newn; 
                break; 
            }
            curr = front; 
            front = front->next; 
        }
        if (front == nullptr) {
            curr->next = newn; 
            newn->prev = curr; 
        }
        return head; 
    }
};
