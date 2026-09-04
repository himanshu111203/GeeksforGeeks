class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        // code here
        int n=arr.size(),sum=0,ans=0;
        for(int j=0;j<m;j++) 
        sum+=arr[j];
        ans=sum;
        int i=1;
        while(i<n){
            sum=sum-arr[i-1]+arr[(i+m-1)%n];
            ans=max(sum,ans);
            i++;
        }
        return ans;
    }
};
