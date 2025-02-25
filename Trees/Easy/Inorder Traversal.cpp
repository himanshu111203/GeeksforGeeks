class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    void in(Node *root,vector<int>&ans){
        if(!root)
        return;
        in(root->left,ans);
        ans.push_back(root->data);
        in(root->right,ans);
    }
    vector<int> inOrder(Node* root) {
        vector<int>ans;
        in(root,ans);
        return ans;
    }
};
