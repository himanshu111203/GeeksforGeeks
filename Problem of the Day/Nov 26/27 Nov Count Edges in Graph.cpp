class Solution {
  public:
    int countEdges(vector<vector<int>> &adj) {
        // code here
        int ans=0,n=adj.size();
        for(int i=0;i<n;i++)
        ans+=adj[i].size();
        return ans/2;
    }
};
