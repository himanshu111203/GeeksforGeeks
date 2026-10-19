class Solution {
  public:
    int count=0;
    vector<bool>vis;
    void dfs(unordered_map<int,vector<int>>&graph,int node){
        count++;
        vis[node]=1;
        for(int i:graph[node]){
            if(!vis[i])
            dfs(graph,i);
        }
    }
    int goodIndices(vector<int> &arr) {
        // code here
        count=0;
        int n=arr.size();
        vis.assign(n+1,0);
        vector<int>adj(n);
        unordered_map<int,vector<int>>graph;
        for(int i=0;i<n;i++)
        adj[i]=(arr[i]+i>=n || arr[i]+i<0)?n:arr[i]+i;
        for(int i=0;i<n;i++)
        graph[adj[i]].push_back(i);
        dfs(graph,n);
        return count-1;
    }
};
