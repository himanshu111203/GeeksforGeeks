class Solution {
  public:
    int getCount(int n, int d) {
        // code here
        int ans=0;
        int start=1,end=n,mid;
        while(start<=end){
            mid=start+(end-start)/2;
            int c=mid,a=0;
            while(c){
                a+=(c%10);
                c/=10;
            }
            if(mid-a>=d){
                ans=n-mid+1;
                end=mid-1;
            }else
            start=mid+1;
        }
        return ans;
    }
};
