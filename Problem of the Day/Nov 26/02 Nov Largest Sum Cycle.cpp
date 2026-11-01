class Solution {
  public:
    int ans=-1;
    void dfs(int node,vector<int>& edge,vector<bool>&vis,vector<bool>&pathvis){
        vis[node]=1;
        pathvis[node]=1;
        if(edge[node]!=-1){
            int adj=edge[node];
            if(!vis[adj])
            dfs(adj,edge,vis,pathvis);
            else if(pathvis[adj]){
                int curr=adj;
                int sum=0;
                do{
                    sum+=curr;
                    curr=edge[curr];
                }while(curr!=adj);
                ans=max(ans,sum);
            }
        }
        pathvis[node]=0;
    }
    int largestSumCycle(vector<int>& edge) {
        // code here
        int n=edge.size();
        vector<bool>vis(n,0),pathvis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i])
            dfs(i,edge,vis,pathvis);
        }
        return ans;
    }
};
