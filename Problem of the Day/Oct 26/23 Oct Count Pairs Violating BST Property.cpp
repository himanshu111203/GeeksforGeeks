/* BST Node Structure
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

  int ans=0;
  vector<int>merge(vector<int>&a,vector<int>&b)
  {
      int n=a.size(),m=b.size();
      a.push_back(1e9);
      b.push_back(1e9);
      vector<int>temp;
      int i=0,j=0;
      for(int k=0;k<n+m;k++)
      {
          if(a[i]<=b[j])
          {
              temp.push_back(a[i++]);
              ans+=j;
          }
          else temp.push_back(b[j++]);

      }
      return temp;

  }
  vector<int>mergesort(vector<int>&v)
  {
      int n=v.size();
      if(n==1) return v;
      vector<int>left,right;
      for(int i=0;i<n;i++)
      {
          if(i<(n/2)) left.push_back(v[i]);
          else right.push_back(v[i]);
      }
      left=mergesort(left);
      right=mergesort(right);
      return merge(left,right);
  }
  void help(Node *root,vector<int>&temp)
  {
      if(!root) return ;
      help(root->left,temp);
      temp.push_back(root->data);
      help(root->right,temp);

  }
    int pairsViolatingBST(Node *root) {
        vector<int>temp;
        help(root,temp);
        ans=0;
        mergesort(temp);
        return ans;

    }
};
