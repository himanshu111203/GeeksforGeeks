class Solution {
  public:
    vector<int>parent,size;
    int find(int x){
        if(parent[x]==x)
        return x;
        return parent[x]=find(parent[x]);
    }
    long long unionbysize(int u,int v){
        int pu=find(u),pv=find(v);
        if(pu==pv)
        return 0;
        long long paths=1LL*size[pu]*size[pv];
        if(size[pv]<=size[pu]){
            parent[pv]=pu;
            size[pu]+=size[pv];
        }else{
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        return paths;
    }
    vector<int> maximumWeight(int n, vector<vector<int>> edges, vector<int>& queries) {
        // code here
        parent.resize(n+1);
        size.assign(n+1,1);
        for(int i=1;i<=n;i++)
        parent[i]=i;
        sort(edges.begin(),edges.end(),[](vector<int>&a,vector<int>&b){
            return a[2]<b[2];
        });
        vector<pair<int,int>>q;
        for(int i=0;i<queries.size();i++)
        q.push_back({queries[i],i});
        sort(q.begin(),q.end());
        vector<int>ans(queries.size());
        int j=0;
        long long total=0;
        for(auto &qu:q){
            int x=qu.first,ind=qu.second;
            while(j<edges.size() && edges[j][2]<=x){
                int u=edges[j][0],v=edges[j][1];
                total+=unionbysize(u,v);
                j++;
            }
            ans[ind]=total;
        }
        return ans;
    }
};
