class Solution {
  public:
    int minSubarraySum(vector<int> &arr) {
        // code here
        int sum=0,ans=INT_MAX;
        for(int i:arr){
            sum+=i;
            ans=min(ans,sum);
            if(sum>0)
            sum=0;
        }
        return ans;
    }
};
