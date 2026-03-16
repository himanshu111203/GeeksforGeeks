/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  void solve(Node* root, long long currSum, int k, 
        unordered_map<long long,int>& mp, int &ans) {

        if (!root)
            return;

        currSum += root->data;

        if (currSum == k)
            ans++;

        if (mp.find(currSum - k) != mp.end())
            ans += mp[currSum - k];

        mp[currSum]++;

        solve(root->left, currSum, k, mp, ans);
        solve(root->right, currSum, k, mp, ans);

        mp[currSum]--; // backtrack
    }

    int countAllPaths(Node *root, int k) {
        // code here
        unordered_map<long long,int> mp;
        int ans = 0;

        solve(root, 0, k, mp, ans);

        return ans;
    }
};
