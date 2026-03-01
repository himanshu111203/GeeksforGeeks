class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int hmax=arr[0],ind=0,n=arr.size();
        for(int i=1;i<n;i++){
            if(arr[i]>hmax){
                hmax=arr[i];
                ind=i;
            }
        }
        int ans=0,lmax=arr[0],rmax=arr[n-1];
        for(int i=1;i<ind;i++){
            if(arr[i]<lmax)
            ans+=(lmax-arr[i]);
            else
            lmax=arr[i];
        }
        for(int i=n-2;i>ind;i--){
            if(arr[i]<rmax)
            ans+=(rmax-arr[i]);
            else
            rmax=arr[i];
        }
        return ans;
    }
};
