class Solution {
  public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        // code here
        int a=1;
        vector<int>jump(n*n+1,-1);
        int x=lad.size(),y=sn.size();
        for(int i=0;i<x;i+=2){
            jump[lad[i]]=lad[i+1];
        }
        for(int i=0;i<y;i+=2){
            jump[sn[i]]=sn[i+1];
        }
        vector<bool>vis(n*n+1,0);
        queue<int>q;
        q.push(1);
        vis[1]=1;
        int count=0;
        while(!q.empty()){
            int m=q.size();
            while(m--){
                int u=q.front();
                q.pop();
                if(u==n*n)
                return count;
                for(int i=1;i<7 && i+u<=n*n;i++){
                    int node=u+i;
                    if(jump[node]!=-1)
                    node=jump[node];
                    if(!vis[node]){
                        q.push(node);
                        vis[node]=1;
                    }
                }
            }
            count++;
        }
        return -1;
    }
};
