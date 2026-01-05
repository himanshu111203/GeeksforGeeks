class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int ans=arr[0];                                           // using sliding window
        for(int i=1;i<k;i++)
        ans^=arr[i];
        int a=ans;
        for(int i=k;i<arr.size();i++){
            a=a^arr[i]^arr[i-k];
            ans=max(ans,a);
        }
        return ans;
    }
};
