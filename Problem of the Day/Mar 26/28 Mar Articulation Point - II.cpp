class Solution {
  public:
  int timer=1;
    void dfs(int node,int parent,vector<vector<int>>&adj,vector<int>&visit,
        vector<int>&tin,vector<int>&low,vector<int>&ans){
        visit[node]=1;
        tin[node]=low[node]=timer++;
        int child=0;
        for(auto it:adj[node]){
            if(it==parent) continue;
            if(!visit[it]){
                dfs(it,node,adj,visit,tin,low,ans);
                low[node]=min(low[node],low[it]);
                if(low[it]>=tin[node] && parent!=-1){
                    ans[node]=1;
                }
                child++;
            }else{
                low[node]=min(low[node],tin[it]);
            }
        }
        if(child>1 && parent==-1)
        ans[node]=1;
    }
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
         vector<int>ans(V,0);
        vector<int>visit(V,0),tin(V),low(V);
        
        for(int i=0;i<V;i++){
            if(!visit[i]){
                dfs(i,-1,adj,visit,tin,low,ans);
            }
        }
        vector<int>result;
        for(int i=0;i<V;i++){
            if(ans[i]==1){
                result.push_back(i);
            }
        }
        
        if(result.size()==0){
            return {-1};
        }
        sort(result.begin(),result.end());
        
       return result; 
    }
};
