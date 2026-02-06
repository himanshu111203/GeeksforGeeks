// by using si+1=si+sum-n*arr[n-1-i]  check on rotation
// s0= a*0 +b*1 + c*2 + d*3 

class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int n=arr.size(),sum=0,total=0;
        for(int i=0;i<n;i++){
            total+=arr[i];
            sum+=arr[i]*i;
        }
        int ans=sum;
        for(int i=n-1;i>0;i--){
            sum=sum+total-n*arr[i];
            ans=max(ans,sum);
        }
        return ans;
    }
};
