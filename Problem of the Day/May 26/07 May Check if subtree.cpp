/*
Definition for Node
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool issub(Node *root1, Node *root2){
        if(!root1 && !root2) return 1;
        if(!root1 || !root2) return 0;
        if(root1->data!=root2->data) return 0;
        return issub(root1->left,root2->left) && issub(root1->right,root2->right);
    }
    bool isSubTree(Node *root1, Node *root2) {
        // code here
        if(!root2) return 1;
        if(!root1) return 0;
        if(issub(root1,root2)) return 1;
        return isSubTree(root1->left,root2) || isSubTree(root1->right,root2);
    }
};
