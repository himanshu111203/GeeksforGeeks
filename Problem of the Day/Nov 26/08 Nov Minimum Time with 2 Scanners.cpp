class Solution {
  public:
    int minTime(int n, int s1, int s2) {
        // code here
        int start=0,end=n*min(s1,s2),ans=0,mid;
        while(start<=end){
            mid=start+(end-start)/2;
            if(mid/s1+mid/s2>=n){
                ans=mid;
                end=mid-1;
            }else
            start=mid+1;
        }
        return ans;
    }
};
