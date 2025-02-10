class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    void inorder(Node *root,vector<int>&arr){
        if(!root)
        return;
        inorder(root->left,arr);
        arr.push_back(root->data);
        inorder(root->right,arr);
    }
    bool isBST(Node* root) {
        vector<int>arr;
        inorder(root,arr);
        for(int i=1;i<arr.size();i++){
            if(arr[i]<arr[i-1])
            return 0;
        }
        return 1;
    }
};
