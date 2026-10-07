class Solution {
  public:
    int maxFrequency(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int j=n-1,gap=0,ans=0;
        for(int i=n-1;i>=0;i--){
            gap+=(arr[j]-arr[i]);
            while(gap>k){
                gap-=(arr[j]-arr[j-1])*(j-i);
                j--;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};
