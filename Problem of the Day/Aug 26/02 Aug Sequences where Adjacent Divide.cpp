class Solution {
  public:
    vector<vector<int>>dp;
    int solve(int ind,int prev,int n,int m){
        if(ind==n)
        return 1;
        if(dp[ind][prev]!=-1)
        return dp[ind][prev];
        int cnt=0;
        for(int i=1;i<=m;i++){
            if((i%prev)==0 || (prev%i)==0)
            cnt+=solve(ind+1,i,n,m);
        }
        return dp[ind][prev]=cnt;
    }
    int count(int n, int m) {
        // code here
        dp.assign(n+1,vector<int>(m+1,-1));
        return solve(0,1,n,m);
    }
};
