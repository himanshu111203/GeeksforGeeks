class Solution {
  public:
    int dp[51][2001];
    int n;
    int solve(int i,vector<int>& arr, int target,int sum){
        if(i==n){
            if(sum==target)
            return 1;
            return 0;
        }
        if(dp[i][sum+1000]!=-1)
        return dp[i][sum+1000];
        return dp[i][sum+1000]=solve(i+1,arr,target,sum+arr[i])+solve(i+1,arr,target,sum-arr[i]);
    }
    int totalWays(vector<int>& arr, int target) {
        //  code here
        n=arr.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,arr,target,0);
    }
};
