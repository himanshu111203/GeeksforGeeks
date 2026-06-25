class Solution {
  public:
    int countWays(string &s1, string &s2) {
        // code here
        int m=s1.size(),n=s2.size();
        const int mod=1e9+7;
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++)
        dp[i][0]=1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=dp[i-1][j];
                if(s1[i-1]==s2[j-1])
                dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
            }
        }
        return dp[m][n];
    }
};
