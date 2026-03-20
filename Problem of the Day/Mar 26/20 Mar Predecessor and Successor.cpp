/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node *pre=NULL,*suc=NULL,*curr=root;
        while(curr){
            if(curr->data<key){
                pre=curr;
                curr=curr->right;
            }
            else if(curr->data>key){
                suc=curr;
                curr=curr->left;
            }
            else{ // root node is eqaul to key
                // find pre (max in left sub tree)
                Node *temp=curr->left;
                while(temp){
                    pre=temp;
                    temp=temp->right;
                }
                // find suc(min in right sub tree)
                temp=curr->right;
                while(temp){
                    suc=temp;
                    temp=temp->left;
                }
                break;
            }
        }
        return {pre,suc};
    }
};
