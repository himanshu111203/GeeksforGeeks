class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int>m;
        m[0]=-1;
        int n=arr.size(),ans=0;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            int rem=((sum%k)+k)%k;
            if(m.count(rem))
            ans=max(ans,i-m[rem]);
            else
            m[rem]=i;
        }
        return ans;
    }
};
