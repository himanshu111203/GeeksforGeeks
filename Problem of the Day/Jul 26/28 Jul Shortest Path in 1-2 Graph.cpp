class Solution {
  public:
    typedef pair<int,int>p;
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {
        // code here
        vector<p>adj[V];
        for(auto &e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        priority_queue<p,vector<p>,greater<p>>q;
        vector<int>dist(V,INT_MAX);
        dist[src]=0;
        vector<bool>visited(V,0);
        q.push({0,src});
        while(!q.empty()){
            int d=q.top().first,u=q.top().second;
            q.pop();
            if(visited[u])
            continue;
            visited[u]=1;
            for(auto &j:adj[u]){
                int v=j.first,w=j.second;
                if(dist[v]>dist[u]+w){
                    dist[v]=dist[u]+w;
                    q.push({dist[v],v});
                }
            }
        }
        return (dist[dest]==INT_MAX)?-1:dist[dest];
    }
};
