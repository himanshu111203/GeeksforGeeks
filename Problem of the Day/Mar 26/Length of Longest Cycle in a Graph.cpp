class Solution {
  public:
    int ans = -1;
    void dfs(int node , unordered_map<int,vector<int>>&adj , vector<int>&vis,
    vector<int>&inRecursion  , vector<int>&dist){
        vis[node]=1;
        inRecursion[node]=1;
        for(auto adj_node:adj[node]){
            if(!vis[adj_node]){
                dist[adj_node] = dist[node]+1;
                dfs(adj_node,adj,vis,inRecursion,dist);
            }
            else if(vis[adj_node] and inRecursion[adj_node]){
                ans = max(ans,dist[node]-dist[adj_node]+1);
            }
        }
        inRecursion[node]=0;
    }
    int longestCycle(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,vector<int>>adj;
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        
        vector<int>vis(V,0);
        vector<int>inRecursion(V,0);
        vector<int>dist(V,1);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,inRecursion,dist);
            }
        }
        return ans;
    }
};
