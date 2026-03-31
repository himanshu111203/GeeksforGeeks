class Solution {
  public:

    int countStrings(int n) {
        // code here
        vector<long long>dp(n+1,0);
        dp[0]=1,dp[1]=2;
        for(int i=2;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2];
        return (int)dp[n];
    }
};
