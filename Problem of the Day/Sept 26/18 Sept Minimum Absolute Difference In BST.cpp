/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; 
*/

class Solution {
  public:
    int ans;
    int prev;
    void solve(Node* root) {
        if(!root)
        return;
        solve(root->left);
        if(prev!=INT_MIN)
        ans=min(ans,root->data-prev);
        prev=root->data;
        solve(root->right);
    }
    int absDiff(Node *root) {
        // code here
        ans=INT_MAX;
        prev=INT_MIN;
        solve(root);
        return ans;
    }
};
