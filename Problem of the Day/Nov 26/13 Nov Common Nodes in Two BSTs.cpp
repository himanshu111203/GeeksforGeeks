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


class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
    vector <int> findCommon(Node *root1, Node *root2)
    {
        vector<int>ans;
        stack<Node*>s1,s2;
        while(root1)
        {
            s1.push(root1);
            root1=root1->left;
        }
        while(root2)
        {
            s2.push(root2);
            root2=root2->left;
        }
        while(!s1.empty()&& !s2.empty())
        {
            if(s1.top()->data==s2.top()->data)
            {
                ans.push_back(s1.top()->data);
                root1=s1.top()->right;
                s1.pop();
                root2=s2.top()->right;
                s2.pop();
            }
            else if(s1.top()->data>s2.top()->data)
            {
                root2=s2.top()->right;
                s2.pop();
            }
            else
            {
                root1=s1.top()->right;
                s1.pop();
            }
            while(root1)
            {
                s1.push(root1);
                root1=root1->left;
            }
            while(root2)
            {
                s2.push(root2);
                root2=root2->left;
            }
        }
        return ans;
    }
};
