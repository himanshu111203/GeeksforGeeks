class Solution {
  public:
    int atmost(vector<int>&arr,int k){
        int i=0,n=arr.size(),ans=0,sum=0;
        for(int j=0;j<n;j++){
            sum+=arr[j];
            while(i<=j && sum>k){
                sum-=arr[i];
                i++;
            }
            ans+=(j-i+1);
        }
        return ans;
    }
    int countSubarray(vector<int>& arr, int l, int r) {
        // code here
        return atmost(arr,r)-atmost(arr,l-1);
    }
};
