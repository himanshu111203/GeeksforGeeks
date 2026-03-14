/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        vector<vector<int>>ans;
        map<int,vector<int>>m;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            Node *temp=it.first;
            int level=it.second;
            m[level].push_back(temp->data);
            if(temp->left)
            q.push({temp->left,level-1});
            if(temp->right)
            q.push({temp->right,level+1});
        }
        for(auto x:m)
        ans.push_back(x.second);
        return ans;
    }
};
