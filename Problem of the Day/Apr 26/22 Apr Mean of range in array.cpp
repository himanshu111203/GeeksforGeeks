class Solution {
  public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        int pre=arr[0];
        for(int i=1;i<arr.size();i++){
            arr[i]+=pre;
            pre=arr[i];
        }
        int n=queries.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int prev=0;
            if(queries[i][0]>0)
            prev=arr[queries[i][0]-1];
            ans[i]=(arr[queries[i][1]]-prev)/(queries[i][1]-queries[i][0]+1);
        }
        return ans;
    }
};
