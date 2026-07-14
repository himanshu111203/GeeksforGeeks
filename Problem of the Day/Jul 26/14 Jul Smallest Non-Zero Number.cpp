class Solution {
  public:  
    bool valid(vector<int>&arr,int mid,int maxi){
        int n=arr.size();
        for(int i=0;i<n;i++){
            long diff=mid-arr[i];
            mid+=diff;
            if(mid>=maxi)
            return 1;
            if(mid<0)
            return 0;
        }
        return 1;
    }
    int find(vector<int>& arr) {
        // code here
        int n=arr.size();
        int maxi=*max_element(arr.begin(),arr.end());
        int start=1,end=maxi+1,mid,ans=-1;
        while(start<=end){
            mid=start+(end-start)/2;
            if(valid(arr,mid,maxi)){
                ans=mid;
                end=mid-1;
            }else
            start=mid+1;
        }
        return ans;
    }
};
