class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        // code here
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> adj[V];
        for(vector<int> edge: edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back({v, edge[2]});
            adj[v].push_back({u, edge[2]});
        }
        
        pq.push({0,0});
        vector<int> dis(V,INT_MAX);
        dis[0] = 0;
        int ans = 0;
        while(!pq.empty()) {
            vector<int> p = pq.top();
            pq.pop();
            int curr = p[1];
            if(curr==V-1 && dis[curr]>=p[0]) {
                ans++;
            }
            for(auto arr: adj[curr]) {
                int v = arr[0];
                if(dis[v]>=(p[0]+arr[1])){
                    dis[v] = p[0]+arr[1];
                    pq.push({dis[v], v});
                }
            }
        }
        return ans;
    }
};
