// Top Down
class Solution {
  public:
    int dp[59];
    int solve(int n){
        if(n==1)
        return 1;
        if(dp[n]!=-1)
        return dp[n];
        int ans=1;
        for(int i=1;i<n;i++){
            ans=max(ans,max(i*(n-i),i*solve(n-i)));
        }
        return dp[n]=ans;
    }
    int maxProduct(int n) {
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};

//Bottom Up
class Solution {
  public:
    int maxProduct(int n) {
        // code here
        vector<int>dp(n+1,0);
        for(int l=2;l<=n;l++){
            for(int cut=1;cut<l;cut++){
                dp[l]=max(dp[l],max(cut*(l-cut),cut*dp[l-cut]));
            }
        }
        return dp[n];
    }
};
