// Top Down
class Solution {
  public:
    int dp[1001][1001];
    int solve(int n,int m,vector<int>&a,vector<int>&b){
        if(m==0)
        return 0;
        if(n==0)
        return INT_MIN;
        if(dp[n][m]!=-1)
        return dp[n][m];
        int take=a[n-1]*b[m-1]+solve(n-1,m-1,a,b);
        int skip=INT_MIN;
        if(n>m)
        skip=solve(n-1,m,a,b);
        return dp[n][m]=max(take,skip);
    }
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        // code here
        int n=a.size(),m=b.size();
        memset(dp,-1,sizeof(dp));
        return solve(n,m,a,b);
    }
};

//Bottom Up
class Solution {
  public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        // code here
        int n=a.size(),m=b.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int j=1;j<=m;j++)
        dp[0][j]=INT_MIN;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int take=a[i-1]*b[j-1]+dp[i-1][j-1];
                int skip=INT_MIN;
                if(i>j)
                skip=dp[i-1][j];
                dp[i][j]=max(take,skip);
            }
        }
        return dp[n][m];
    }
};

// Space Optomization
class Solution {
  public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        // code here
        int n=a.size(),m=b.size();
        vector<int>prev(m+1,0);
        for(int j=1;j<=m;j++)
        prev[j]=INT_MIN;
        for(int i=1;i<=n;i++){
            vector<int>curr(m+1,0);
            for(int j=1;j<=m;j++){
                int take=INT_MIN;
                if(prev[j-1]!=INT_MIN)
                take=a[i-1]*b[j-1]+prev[j-1];
                int skip=INT_MIN;
                if(i>j)
                skip=prev[j];
                curr[j]=max(take,skip);
            }
            prev=curr;
        }
        return prev[m];
    }
};
