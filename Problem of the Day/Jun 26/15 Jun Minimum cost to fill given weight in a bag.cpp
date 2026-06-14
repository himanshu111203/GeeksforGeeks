//Top Down Approach
class Solution {
  public:
    int dp[2001][2001];
    int solve(int n,vector<int> &cost, int w){
        if(w==0)
        return 0;
        if(n==0)
        return INT_MAX;
        if(dp[n][w]!=-1)
        return dp[n][w];
        int skip=solve(n-1,cost,w);
        int take=INT_MAX;
        if(cost[n-1]!=-1 && w>=n){
            int sub=solve(n,cost,w-n);
            if(sub!=INT_MAX)
            take=cost[n-1]+sub;
        }
        return dp[n][w]=min(take,skip);
    }
    int minimumCost(vector<int> &cost, int w) {
        // code here
        int n=cost.size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(n,cost,w);
        return (ans==INT_MAX)?-1:ans;
    }
};

//Bottom Up Approach
class Solution {
  public:
    int minimumCost(vector<int> &cost, int w) {
        // code here
        int n=cost.size();
        vector<vector<int>>dp(n+1,vector<int>(w+1,0));
        for(int j=1;j<=w;j++)
        dp[0][j]=INT_MAX;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=w;j++){
                int skip=dp[i-1][j];
                int take=INT_MAX;
                if(cost[i-1]!=-1 && j>=i){
                    int sub=dp[i][j-i];
                    if(sub!=INT_MAX)
                    take=cost[i-1]+sub;
                }
                dp[i][j]=min(skip,take);
            }
        }
        return (dp[n][w]==INT_MAX)?-1:dp[n][w];
    }
};
