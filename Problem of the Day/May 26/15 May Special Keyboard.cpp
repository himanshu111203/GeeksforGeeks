class Solution {
  public:
    int optimalKeys(int n) {
        // code here
        if(n<7)
        return n;
        vector<int>dp(n+1,0);
        for(int i=0;i<7;i++)
        dp[i]=i;
        for(int i=7;i<=n;i++){
            for(int j=i-3;j>=1;j--)
            dp[i]=max(dp[i],dp[j]*(i-j-1));
        }
        return dp[n];
    }
};
