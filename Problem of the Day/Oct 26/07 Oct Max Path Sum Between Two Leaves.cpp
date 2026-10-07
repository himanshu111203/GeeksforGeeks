/* Node Structure
class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = nullptr;
        right = nullptr;
    }
}
*/
class Solution {
  public:
    int ans=INT_MIN;
    int find(Node *root){
        if(!root)
        return 0;
        if(!root->left && !root->right)
        return root->data;
        int l=find(root->left);
        int r=find(root->right);
        if(!root->left)
        return root->data+r;
        if(!root->right)
        return root->data+l;
        ans=max(ans,l+r+root->data);
        return root->data+max(l,r);
    }
    int maxPathSum(Node *root) {
        // code here
        int temp=find(root);
        if(ans==INT_MIN)
        return -1;
        return ans;
    }
};
