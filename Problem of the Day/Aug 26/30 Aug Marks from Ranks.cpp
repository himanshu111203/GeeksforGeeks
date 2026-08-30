class Solution {
  public:
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
        // code here
        vector<int>rnk,ans;
        int n=l.size();
        for(int i=0;i<n;i++){
            for(int j=l[i];j<=r[i];j++)
            rnk.push_back(j);
        }
        for(int q:rank)
        ans.push_back(rnk[q-1]);
        return ans;
    }
};
