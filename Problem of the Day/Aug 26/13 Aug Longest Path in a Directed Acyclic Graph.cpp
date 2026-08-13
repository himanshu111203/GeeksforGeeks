class Solution {
  public:
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
        // code here
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto &e:edges){
            int u=e[0],v=e[1],w=e[2];
            adj[u].push_back({v, w});
        }
        vector<int>dist(V,INT_MIN);
        priority_queue<pair<int,int>>pq;
        pq.push({0,src});
        dist[src]=0;
        while(!pq.empty()){
            auto [w,u]=pq.top();
            pq.pop();
            for(auto &[v,d]:adj[u]){
                int totalDistance=w +d;
                
                if(dist[v]<totalDistance){
                    dist[v]=totalDistance;
                    pq.push({totalDistance,v});
                }
            }
        }
        return dist;
    }
};
