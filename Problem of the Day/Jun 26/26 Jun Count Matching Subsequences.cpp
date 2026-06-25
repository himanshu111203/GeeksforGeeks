//Top Down 
class Solution {
  public:
    int dp[1001][1001];
    const int mod=1e9+7;
    int count(int m,int n,string &s1, string &s2){
        if(n==0)
        return 1;
        if(m==0)
        return 0;
        if(dp[m][n]!=-1)
        return dp[m][n];
        int ans;
        if(s1[m-1]!=s2[n-1])
        ans=count(m-1,n,s1,s2);
        else
        ans=(count(m-1,n,s1,s2)+count(m-1,n-1,s1,s2))%mod;
        return dp[m][n]=ans;
    }
    int countWays(string &s1, string &s2) {
        // code here
        int m=s1.size(),n=s2.size();
        memset(dp,-1,sizeof(dp));
        return count(m,n,s1,s2);
    }
};


//Bottom Up
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
