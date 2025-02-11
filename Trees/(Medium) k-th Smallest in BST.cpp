class Solution {
  public:
    void inorder(Node *root,vector<int>&arr){
        if(!root)
        return;
        inorder(root->left,arr);
        arr.push_back(root->data);
        inorder(root->right,arr);
    }
    // Return the Kth smallest element in the given BST
    int kthSmallest(Node *root, int k) {
        vector<int>arr;
        inorder(root,arr);
        if(k>arr.size())
        return -1;
        return arr[k-1];
    }
};
