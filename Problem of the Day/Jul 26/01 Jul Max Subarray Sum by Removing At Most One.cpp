// Top Down
class Solution {
  public:
    int dp[1000001][2];
    int solve(int n,vector<int>&arr,int can){
        if(n==1)
        return arr[0];
        if(dp[n][can]!=INT_MIN)
        return dp[n][can];
        if(can)
        return dp[n][can]=max({arr[n-1],arr[n-1]+solve(n-1,arr,1),solve(n-1,arr,0)});
        return dp[n][can]=max(arr[n-1],arr[n-1]+solve(n-1,arr,0));
    }
    int maxSumSubarray(vector<int>& arr) {
        // code here
        int n=arr.size();
        for(int i=0;i<=n;i++){
            dp[i][0]=INT_MIN;
            dp[i][1]=INT_MIN;
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            ans=max(ans,solve(i,arr,1));
            ans=max(ans,solve(i,arr,0));
        }
        return ans;
    }
};

// Bottom Up
class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(2,INT_MIN));
        dp[0][0]=arr[0];
        dp[0][1]=arr[0];
        int ans=arr[0];
        for(int i=1;i<n;i++){
            dp[i][1]=max({arr[i],arr[i]+dp[i-1][1],dp[i-1][0]});
            dp[i][0]=max(arr[i],arr[i]+dp[i-1][0]);
            ans=max({ans,dp[i][1],dp[i][0]});
        }
        return ans;
    }
};

// Space optimized
class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(2,INT_MIN));
        int oneskip=arr[0];
        int noskip=arr[0];
        int ans=arr[0];
        for(int i=1;i<n;i++){
            int newnoskip=max({arr[i],arr[i]+noskip,oneskip});
            int newoneskip=max(arr[i],arr[i]+oneskip);
            oneskip=newoneskip;
            noskip=newnoskip;
            ans=max({ans,noskip,oneskip});
        }
        return ans;
    }
};
