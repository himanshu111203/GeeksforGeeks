class Solution {
  public:
    int maximumSubarray(vector<int>& arr) {
        // code here
        int n=arr.size();
        int ans=INT_MIN,sum=0,dsum=0;
        for(int i=0;i<n;i++){
            sum=max(sum+arr[i],dsum+arr[i]*arr[i]);
            dsum=max(dsum+arr[i],0);
            ans=max(ans,max(sum,dsum));
        }
        return ans;
    }
};
