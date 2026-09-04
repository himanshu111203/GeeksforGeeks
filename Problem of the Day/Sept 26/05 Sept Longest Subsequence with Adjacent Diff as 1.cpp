class Solution {
  public:
    int longestSubseq(vector<int>& arr) {
        // code here
        unordered_map<int,int>dp;
        int ans=0;
        for(int x:arr){
            int prev=max(dp[x-1],dp[x+1]);
            dp[x]=prev+1;
            ans=max(ans,dp[x]);
        }
        return ans;
    }
};
