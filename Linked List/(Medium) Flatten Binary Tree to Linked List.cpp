class Solution
{
    public:
    void flatten(Node *root)
    {
        Node *curr=root;
        while(curr){
            if(curr->left){
                Node *prev=curr->left;
                while(prev->right){
                    prev=prev->right;
                }
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }
};
