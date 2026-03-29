class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int total=0;
        for(int i:arr)
        total+=i;
        int target=total+diff;
        if(target%2!=0)
        return 0;
        target/=2;
        vector<int>dp(target+1,0);
        dp[0]=1;
        for(int num:arr){
            for(int i=target;i>=num;i--){
                dp[i]+=dp[i-num];
            }
        }
        return dp[target];
    }
};
