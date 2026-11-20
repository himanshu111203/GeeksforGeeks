class Solution {
  public:
    int smallestSubWithSum(vector<int>& arr, int x) {
        // code here
        int j=0,ans=INT_MAX,sum=0,n=arr.size();
        for(int i=0;i<n;i++){
            sum+=arr[i];
            while(j<=i && sum>x){
                ans=min(ans,i-j+1);
                sum-=arr[j++];
            }
        }
        return (ans==INT_MAX)?0:ans;
    }
};
