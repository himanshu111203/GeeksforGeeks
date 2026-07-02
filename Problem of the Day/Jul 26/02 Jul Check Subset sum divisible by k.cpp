class Solution {
  public:
    bool divisibleByK(vector<int>& arr, int k) {
        // code here
        vector<bool>dp(k,0);
        for(int i:arr){
            vector<bool>temp(dp);
            temp[i%k]=1;
            for(int rem=0;rem<k;rem++){
                if(dp[rem])
                temp[(rem+i)%k]=1;
            }
            dp=temp;
            if(dp[0])
            return 1;
        }
        return 0;
    }
};
