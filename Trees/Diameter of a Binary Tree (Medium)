class Solution {
  public:
    int solver(Node* root,int &ans){
        if(!root)
        return 0;
        int l = solver(root->left , ans);
        int r = solver(root->right , ans);
        ans=max(ans,l+r);
        return 1+max(l,r);
    }
    int diameter(Node* root) {
        // Your code here
        int ans = 0;
        solver(root,ans);
        return ans;
    }
};
