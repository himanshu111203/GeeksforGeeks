class Solution {
  public:
    int dfs(int val,vector<int> &b,vector<bool>&visited){
        if(visited[val])
        return 0;
        visited[val]=1;
        return 1+dfs(b[val-1],b,visited);
    }
    int minOperations(vector<int> &b) {
        // code here
        int n=b.size();
        long long ans=1;
        int mod=1e9+7;
        vector<bool>visited(n+1,0);
        for(int i=0;i<n;i++){
            if(!visited[b[i]]){
                int len=dfs(b[i],b,visited);
                ans=lcm(ans,len);
            }
        }
        return ans%mod;
    }
};
