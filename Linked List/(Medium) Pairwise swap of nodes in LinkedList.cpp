struct Node* pairwise_swap(struct Node* head)
{
    Node *curr=head;
    while(curr && curr->next){
        int a=curr->data;
        curr->data=curr->next->data;
        curr->next->data=a;
        curr=curr->next->next;
    }
    return head;
}
