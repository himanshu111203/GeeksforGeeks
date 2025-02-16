class Solution {
  public:
    // Function to return maximum path sum from any node in a tree.
    int solve(Node *root,int &ans){
        if(!root)
        return 0;
        int left=solve(root->left,ans);
        int right=solve(root->right,ans);
        if(left<0)
        left=0;
        if(right<0)
        right=0;
        ans=max(ans,root->data+left+right);
        return root->data+max(left,right);
    }
    int findMaxSum(Node *root) {
        int ans=INT_MIN;
        int temp=solve(root,ans);
        return ans;
    }
};
