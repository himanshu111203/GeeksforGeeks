class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &queries) {
        // code here
        vector<int>ans;
        ans.push_back(0);
        int xr=0;
        for(int i=0;i<queries.size();i++){
            if(queries[i][0]==0)
            ans.push_back(queries[i][1]^xr);
            else{
               int x=queries[i][1];
               xr^=x;
            }
        }
        for(int i=0;i<ans.size();i++)
        ans[i]^=xr;
        sort(ans.begin(),ans.end());
        return ans;
    }
};
