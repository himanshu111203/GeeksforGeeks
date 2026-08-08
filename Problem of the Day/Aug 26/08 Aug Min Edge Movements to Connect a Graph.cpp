class Solution {
  public:
    vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(parent[x]==x)
        return x;
        return parent[x]=find(parent[x]);
    }
    void unionbyrank(int u,int v){
        int pu=find(u),pv=find(v);
        if(rank[pu]>rank[pv])
        parent[pv]=parent[pu];
        else if(rank[pu]<rank[pv])
        parent[pu]=pv;
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        // code here
        int sz=edges.size();
        if(sz<n-1)
        return -1;
        parent.resize(n);
        rank.assign(n,1);
        for(int i=0;i<n;i++)
        parent[i]=i;
        int components=n;
        for(auto &e:edges){
            if(find(e[0])!=find(e[1])){
                unionbyrank(e[0],e[1]);
                components--;
            }
        }
        return components-1;
    }
};
