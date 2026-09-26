class Solution {
  public: 
    int sm,med,ln,csm,cmed,cln;
    vector<int>dp;
    int solve(int x){
        if(x<=0)
        return 0;
        if(dp[x]!=-1)
        return dp[x];
        int ans=INT_MAX;
        ans=min(ans,csm+solve(x-sm));
        ans=min(ans,cmed+solve(x-med));
        ans=min(ans,cln+solve(x-ln));
        return dp[x]=ans;
        
    }
    int minimumCost(int x, int s, int m, int l, int cs, int cm, int cl) {
        // code here
        sm=s,csm=cs,med=m,cmed=cm,ln=l,cln=cl;
        dp.assign(x+1,-1);
        return solve(x);
    }
};
