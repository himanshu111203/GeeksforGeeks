/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    Node *lcs(Node *root,int p,int q){
        if(!root || root->data==p || root->data==q){
            return root;
        } 
        Node* l=lcs(root->left,p,q);
        Node* r=lcs(root->right,p,q);
        if(l && r)
        return root;
        else if(l)
        return l;
        else
        return r;
    }
    int solver(Node *root,int p,int q,int prev){
        if(!root)
        return 1e9;
        if(root->data==p || root->data==q)
        return 0;
        int ans=1e9;
        if(!prev)
        ans=min({ans,0+solver(root->left,p,q,0),1+solver(root->right,p,q,1)});
        else
        ans=min({ans,1+solver(root->left,p,q,0),0+solver(root->right,p,q,1)});
        return ans;
    }
    int numberOfTurns(Node* root, int p, int q) {
        // code here
        Node *ances=lcs(root,p,q);
        int left=solver(ances->left,p,q,0);
        int right=solver(ances->right,p,q,1);
        int ans=0;
        if(left<1e9)
        ans+=left;
        if(right<1e9)
        ans+=right;
        ans++;
        if(ances->data==p || ances->data==q)
        ans--;
        if(ans==0)
        return -1;
        return ans;
    }
};
