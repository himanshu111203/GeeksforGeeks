/* Structure of a Binary Search Tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int minDiff(Node *root, int k) {
        // code here
        int diff=INT_MAX;
        while(root){
            if(root->data==k)
            return 0;
            else if(root->data<k){
                if(diff>k-root->data)
                diff=k-root->data;
                root=root->right;
            }else{
                if(diff>root->data-k)
                diff=root->data-k;
                root=root->left;
            }
        }
        return diff;
    }
};
