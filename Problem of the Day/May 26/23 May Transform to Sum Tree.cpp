/* Structure for Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    int find(Node *root){
        if(!root)
        return 0;
        int l=find(root->left);
        int r=find(root->right);
        int x=root->data;
        root->data=l+r;
        return x+l+r;
    }
    void toSumTree(Node *root) {
        // code here
        int x=find(root);
    }
};
