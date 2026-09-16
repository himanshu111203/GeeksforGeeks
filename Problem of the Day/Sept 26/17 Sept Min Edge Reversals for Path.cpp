class Solution {
  public:
    typedef pair<int,int>p;
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
        // code here  
        vector<p>adj[n+1];
        for(auto &e:edges){
            int u=e[0],v=e[1];
            adj[u].push_back({v,0}); 
            adj[v].push_back({u,1});
        }
        priority_queue<p,vector<p>,greater<p>>q;
        q.push({0,src});
        vector<bool>explored(n+1,0);
        vector<int>dist(n+1,INT_MAX);
        dist[src]=0;
        while(!q.empty()){
            int u=q.top().second,cost=q.top().first;
            q.pop();
            if(explored[u])
            continue;
            explored[u]=1;
            for(auto &[v,w]:adj[u]){
                if(dist[v]>w+cost){
                    dist[v]=w+cost;
                    q.push({dist[v],v});
                }
            }
        }
        return (dist[dst]==INT_MAX)?-1:dist[dst];
    }
};
