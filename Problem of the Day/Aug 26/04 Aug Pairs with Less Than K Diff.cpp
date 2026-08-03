class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        // code here
        int n=arr.size(),ans=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-1;i++){
            int start=i+1,end=n-1,mid,temp=0;
            while(start<=end){
                mid=start+(end-start)/2;
                if((arr[mid]-arr[i])<k){
                    temp=mid-i;
                    start=mid+1;
                }else
                end=mid-1;
            }
            ans+=temp;
        }
        return ans;
    }
};
