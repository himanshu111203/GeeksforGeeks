class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here                                             // Use Sliding Window
        int ans=0;
        for(int i=0;i<k;i++)
        ans+=arr[i];
        int a=ans;
        for(int i=k;i<arr.size();i++){
            a=a+arr[i]-arr[i-k];
            ans=max(ans,a);
        }
        return ans;
    }
};
