class Solution {
  public:
    TreeNode* linkedListToBinaryTree(Node* head) {
        TreeNode *ans=new TreeNode(head->data);
        head=head->next;
        queue<TreeNode*>q;
        q.push(ans);
        while(!q.empty() && head){
            TreeNode* temp=q.front();
            q.pop();
            temp->left=new TreeNode(head->data);
            head=head->next;
            q.push(temp->left);
            if(head){
                temp->right=new TreeNode(head->data);
                head=head->next;
                q.push(temp->right);
            }
        }
        return ans;
    }
};
