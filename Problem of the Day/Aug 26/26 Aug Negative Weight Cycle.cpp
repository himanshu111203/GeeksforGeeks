class Solution {
  public:
    bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>dist(V,1e8);
        dist[0]=0;
        while(--V){
            bool flag=1;
            for(auto &e:edges){
                int u=e[0],v=e[1],w=e[2];
                if(dist[u]!=1e8 && dist[u]+w<dist[v]){
                    flag=0;
                    dist[v]=dist[u]+w;
                }
            }
            if(flag)
            return 0;
        }
        for(auto &e:edges){
            int u=e[0],v=e[1],w=e[2];
            if(dist[u]!=1e8 && dist[u]+w<dist[v])
            return 1;
        }
        return 0;
    }
};
