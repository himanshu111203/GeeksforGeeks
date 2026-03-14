/*
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
    vector<int> topView(Node *root) {
        // code here
        vector<int>ans;
        map<int,int>m; // level position, node data
        queue<pair<Node*,int>>q;  // Node , Level
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            Node *temp=it.first;
            int level=it.second;
            if(m.find(level)==m.end())
            m[level]=temp->data;
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
