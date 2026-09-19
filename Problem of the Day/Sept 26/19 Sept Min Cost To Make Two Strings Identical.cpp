//TopDown
class Solution {
  public:
    vector<vector<int>>dp;
    int solve(int m,int n,string &s1,string &s2,int c1,int c2){
        if(m==0)
        return c2*n;
        if(n==0)
        return c1*m;
        if(dp[m][n]!=-1)
        return dp[m][n];
        if(s1[m-1]==s2[n-1])
        return dp[m][n]=solve(m-1,n-1,s1,s2,c1,c2);
        else
        return dp[m][n]=min(c1+solve(m-1,n,s1,s2,c1,c2),c2+solve(m,n-1,s1,s2,c1,c2));
    }
    int findMinCost(string &s1, string &s2, int costS1, int costS2) {
        // code here
        int m=s1.size(),n=s2.size();
        dp.assign(m+1,vector<int>(n+1,-1));
        return solve(m,n,s1,s2,costS1,costS2);
    }
};

//Bottom Up
class Solution {
  public:
    int findMinCost(string &s1, string &s2, int costS1, int costS2) {
        // code here
        int m=s1.size(),n=s2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int j=1;j<=n;j++)
        dp[0][j]=j*costS2;
        for(int i=1;i<=m;i++)
        dp[i][0]=i*costS1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];
                else
                dp[i][j]=min(costS1+dp[i-1][j],costS2+dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};
