class Solution {
  public:
    int countStrings(int n, int k) {
        // code here
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        dp[1][0][0]=1;
        dp[1][1][0]=1;
        int mod=1000000007;
        for(int i=1;i<n;i++){
            for(int j=0;j<=k;j++){
                dp[i+1][0][j]=(dp[i+1][0][j]+dp[i][0][j])%mod;
                dp[i+1][1][j]=(dp[i+1][1][j]+dp[i][0][j])%mod;
                dp[i+1][0][j]=(dp[i+1][0][j]+dp[i][1][j])%mod;
                if(j+1<=k)
                dp[i+1][1][j+1]=(dp[i+1][1][j+1]+dp[i][1][j])%mod;
            }
        }
        return (dp[n][0][k]+dp[n][1][k])%mod;
    }
};
