/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
class Solution {
  public:
    int l=0,r=0;
    void find(Node* root,int c){
        if(!root)
        return;
        l=min(l,c);
        r=max(r,c);
        find(root->left,c-1);
        find(root->right,c+1);
    }
    void sum(Node* root,vector<int>&ans,int c){
        if(!root)
        return;
        ans[c]+=root->data;
        sum(root->left,ans,c-1);
        sum(root->right,ans,c+1);
    }
    vector<int> verticalSum(Node* root) {
        // code here
        find(root,0);
        vector<int>ans(r-l+1,0);
        sum(root,ans,-1*l);
        return ans;
    }
};
