int n1,n2;
class Solution {
  public:
  void find(Node *root,vector<int>&ans)
  {
      if(!root)
      return;
      if(root->data>n1 && root->data>n2)
      find(root->left,ans);
      else if(root->data<n1 && root->data<n2)
      find(root->right,ans);
      else
      {
          find(root->left,ans);
          ans.push_back(root->data);
          find(root->right,ans);
      }
  }
    vector<int> printNearNodes(Node *root, int low, int high) {
        vector<int>ans;
        n1=low,n2=high;
        find(root,ans);
        return ans;
    }
};
