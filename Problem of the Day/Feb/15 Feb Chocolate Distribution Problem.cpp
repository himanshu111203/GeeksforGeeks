class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        sort(a.begin(),a.end());
        int ans=INT_MAX;
        for(int i=m-1;i<a.size();i++){
            ans=min(ans,a[i]-a[i+1-m]);
        }
        return ans;
    }
};
