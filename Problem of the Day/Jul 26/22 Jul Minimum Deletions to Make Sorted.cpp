class Solution {
  public:
    int minDeletions(vector<int>& arr) {
        // code here
        vector<int>lis;
        for(int i:arr){
            if(lis.empty() || lis.back()<i){
                lis.push_back(i);
                continue;
            }
            int start=0,end=lis.size()-1,mid,ind;
            while(start<=end){
                mid=start+(end-start)/2;
                if(lis[mid]>=i){
                    ind=mid;
                    end=mid-1;
                }else
                start=mid+1;
            }
            lis[ind]=i;
        }
        return arr.size()-lis.size();
    }
};
