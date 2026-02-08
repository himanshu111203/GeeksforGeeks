class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        if(arr[0]<=arr[n-1])
        return 0;
        int start=0,end=n-1,mid,ans;
        while(start<=end){
            mid=start+(end-start)/2;
            if(arr[0]<=arr[mid])
            start=mid+1;
            else{
                ans=mid;
                end=mid-1;
            }
        }
        return ans;
    }
};
