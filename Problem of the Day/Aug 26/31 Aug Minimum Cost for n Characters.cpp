class Solution {
  public:
    int solve(int n, int i, int d, int c, vector<int>& dp) {
        if(n==0)
        return 0;
        if(n==1)
        return i;
        if(dp[n]!=-1)
        return dp[n];
        int ans=i*n;
        if(n%2==0)
        ans=min(ans,c+solve(n/2,i,d,c,dp));
        else{
            // apply one extra add ko delete kiya then copy laga diya
            ans=min(ans,d+c+solve((n+1)/2,i,d,c,dp));
            // ek extra remove karka man liya fir add kar denga toh dono cost add kar de
            ans=min(ans,i+c+solve((n-1)/2,i,d,c,dp));
        }
        return dp[n]=ans;
    }
    int minCost(int n, int i, int d, int c) {
        // code here
        vector<int> dp(n+1,-1);
        return solve(n,i,d,c,dp);
    }
};
