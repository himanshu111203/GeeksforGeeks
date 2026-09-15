/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    int getCount(Node *root, int k) {
        // code here
        vector<int>tmp;
        queue<Node*>q;
        q.push(root);
        int lvl=1;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                Node* node=q.front();
                q.pop();
                if(!node->left && !node->right)
                tmp.push_back(lvl);
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
            }
            lvl++;
        }
        sort(tmp.begin(), tmp.end());
        int cnt=0;
        for(int &i:tmp){
            if(k>=i){
                k-=i;
                cnt++;
            }else
            break;
        }
        return cnt;
    }
};
