class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if(node == NULL)
        return;
        
        //Invert  pointers    
        Node* left = node->left;
        node->left = node->right;
        node->right = left;
        
        //Do the same for both TREES
        mirror(node->left);
        mirror(node->right);
    }
};
