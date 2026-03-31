class Solution {
  public:
    int maxProfit(vector<int>& arr, int k) {
        // Code here
        int ans=0,n=arr.size(),mini=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]>mini && (arr[i]-mini)>k){
                ans+=(arr[i]-mini-k);
                mini=arr[i]-k;
            }
            else
            mini=min(mini,arr[i]);
        }
        return ans;
    }
};
