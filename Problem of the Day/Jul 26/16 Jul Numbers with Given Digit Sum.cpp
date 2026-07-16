// first digit not include 0

// hnadling first case in solve function
class Solution {
  public:
    vector<vector<int>>dp;
    int solve(int n,int sum,bool first){
        if(n==0)
        return sum==0;
        if(dp[n][sum]!=-1)
        return dp[n][sum];
        int ans=0;
        int a=0;
        if(first)
        a++;
        for(int i=a;i<10;i++){
            int take=0;
            if(sum>=i)
            take=solve(n-1,sum-i,0);
            ans+=take;
        }
        return dp[n][sum]=ans;
    }
    int countWays(int n, int sum) {
        // code here
        dp.assign(n+1,vector<int>(sum+1,-1));
        int ans=solve(n,sum,1);
        return (ans==0)?-1:ans;
    }
};

// handling first digit case in main function
class Solution {
  public:
    vector<vector<int>>dp;
    int solve(int n,int sum){
        if(n==0)
        return sum==0;
        if(dp[n][sum]!=-1)
        return dp[n][sum];
        int ans=0;
        for(int i=0;i<10;i++){
            int take=0;
            if(sum>=i)
            take=solve(n-1,sum-i);
            ans+=take;
        }
        return dp[n][sum]=ans;
    }
    int countWays(int n, int sum) {
        // code here
        dp.assign(n+1,vector<int>(sum+1,-1));
        int ans=0;
        for(int i=1;i<10;i++){
            if(sum>=i)
            ans+=solve(n-1,sum-i);
        }
        return (ans==0)?-1:ans;
    }
};
