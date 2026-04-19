class Solution {
  public:
    int fun(int n,vector<int>&dp){
        if(n<=3)
        return n-1;
        if(dp[n]!=-1)
        return dp[n];
        if(n%2==0)
        return dp[n]=(n*fun(n-1,dp))+1;
        return dp[n]=(n*fun(n-1,dp))-1;
    }
    int derangeCount(int n) {
        // code here
        vector<int>dp(n+1,-1);
        int ans=fun(n,dp);
        return ans;
    }
};
