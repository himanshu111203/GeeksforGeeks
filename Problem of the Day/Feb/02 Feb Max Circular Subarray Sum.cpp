class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int mini=INT_MAX,sum=0,ksum=0,misum=0,maxi=INT_MIN;;
        for(int i=0;i<arr.size();i++){
            misum+=arr[i];
            sum+=arr[i];
            ksum+=arr[i];
            mini=min(mini,misum);
            maxi=max(maxi,ksum);
            if(ksum<0)
            ksum=0;
            if(misum>0)
            misum=0;
        }
        if(sum==mini)
        return maxi;
        return max(maxi,sum-mini);
    }
};
