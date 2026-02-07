class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int prodl=INT_MIN,prodr=INT_MIN;
        int temp1=1,temp2=1;
        int n=arr.size();
        for(int i=0;i<n;i++){
            temp1*=arr[i];
            temp2*=arr[n-i-1];
            prodl=max(prodl,temp1);
            prodr=max(prodr,temp2);
            if(temp1==0)
            temp1=1;
            if(temp2==0)
            temp2=1;
        }
        return max(prodl,prodr);
    }
};
