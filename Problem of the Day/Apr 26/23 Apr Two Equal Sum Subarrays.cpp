class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int sum=0,pre=0,n=arr.size();
        for(int i=0;i<n;i++)
        sum+=arr[i];
        for(int i=0;i<n;i++){
            pre+=arr[i];
            if(2*pre==sum)
            return 1;
        }
        return 0;
    }
};
