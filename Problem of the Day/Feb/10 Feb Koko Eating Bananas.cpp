class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int n=arr.size(),start=1,end=0;
        for(int i:arr){
            end=max(end,i);
        }
        int mid,ans=end;
        while(start<=end){
            mid=start+(end-start)/2;
            int hr=0;
            for(int i:arr){
                hr+=i/mid;
                if(i%mid)
                hr++;
            }
            if(hr>k)
            start=mid+1;
            else{
                ans=mid;
                end=mid-1;
            }
        }
        return ans;
    }
};
