class Solution {
  public:
    pair<int,int> func(vector<vector<int>> &adj,int i){
        int n = adj.size();
        queue<int> q;
        q.push(i);
        vector<int> dist(n,-1);
        dist[i] = 0;
        int last_dist = 0;
        int last_node = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i<size;i++){
                int curr = q.front();
                q.pop();
                for(int x : adj[curr]){
                    if(dist[x-1] == -1){
                        dist[x-1] = dist[curr] + 1;
                        q.push(x-1);
                    }
                }
                if(dist[curr] > last_dist){
                    last_dist = dist[curr];
                    last_node = curr;
                }
            }
        }
        return {last_node,last_dist};
    }
    int partyHouse(vector<vector<int>> &adj) {
        // code here
        pair<int,int> p1 = func(adj,0);
        pair<int,int> p2 = func(adj,p1.first);
        return (p2.second + 1) / 2;
    }
};
