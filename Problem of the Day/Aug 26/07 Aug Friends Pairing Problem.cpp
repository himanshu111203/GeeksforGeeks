class Solution {
  public:
    int countFriendsPairings(int n) {
        // code here
        if(n<3)
        return n;
        vector<int>dp(n+1);
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
        dp[i]=dp[i-1]+(i-1)*dp[i-2];
        return dp[n];
    }
};
