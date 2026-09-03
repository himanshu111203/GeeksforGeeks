//Top Down
class Solution {
  public:
    int n;
    map<pair<int,int>,int>dp;
    int solve(int i,int prev,vector<int>&arr){
        if(i==n)
        return 0;
        if(dp.count({i,prev}))
        return dp[{i,prev}];
        int curr=arr[i];
        int keep=abs(curr-prev)+solve(i+1,curr,arr);
        int replace=abs(1-prev)+solve(i+1,1,arr);
        return dp[{i,prev}]=max(keep,replace);
        
    }
    int maxDiffSum(vector<int>& arr) {
        // code here
        n=arr.size();
        if(n==1)
        return 0;
        return max(solve(1,arr[0],arr),solve(1,1,arr));
    }
};

//Bottom Up
class Solution {
  public:
    int maxDiffSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        if(n==1)
        return 0;
        vector<vector<int>>dp(n,vector<int>(2));
        // First element:
        // 0 -> keep arr[0]
        // 1 -> replace by 1
        dp[0][0]=0,dp[0][1]=0;
        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0]+abs(arr[i]-arr[i-1]),dp[i-1][1]+abs(arr[i]-1));
            dp[i][1]=max(dp[i-1][0]+abs(1-arr[i-1]),dp[i-1][1]+abs(1-1));
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};
