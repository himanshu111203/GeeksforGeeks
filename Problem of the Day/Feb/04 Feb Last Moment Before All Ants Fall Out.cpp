class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        int ans = 0;
        int l = 0, r = n;
        for(int i=0;i<left.size();i++)   
        ans = max(ans,left[i]-l);
        for(int i=0;i<right.size();i++)  
        ans = max(ans,r-right[i]);
        return ans;
    }
};
