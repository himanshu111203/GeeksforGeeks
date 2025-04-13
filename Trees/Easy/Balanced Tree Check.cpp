class Solution {
  public:
    int height(Node *root){
        if(!root)
        return 0;
        return max(1+height(root->left),1+height(root->right));
    }
    bool isBalanced(Node* root) {
        if(!root)
        return 1;
        int l=height(root->left);
        int r=height(root->right);
        if(abs(l-r)>1)
        return 0;
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        if(!left || !right)
        return 0;
        return 1;
    }
};
