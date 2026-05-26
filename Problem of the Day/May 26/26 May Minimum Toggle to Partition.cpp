class Solution {
  public:
    int minToggle(vector<int>& arr) {
        // code here
        int n=arr.size(),co=0,cz=0;
        vector<int>ones(n,0),zeros(n,0);
        for(int i=0;i<n;i++){
            ones[i]=co;
            if(arr[i]==1)
            co++;
            int indz=n-i-1;
            zeros[indz]=cz;
            if(arr[indz]==0)
            cz++;
        }
        int ans=n;
        for(int i=0;i<n;i++){
            ans=min(ans,zeros[i]+ones[i]);
        }
        return ans;
    }
};
