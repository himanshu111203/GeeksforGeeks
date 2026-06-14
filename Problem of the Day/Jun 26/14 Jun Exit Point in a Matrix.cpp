class Solution {
  public:
    int row[4]={0,1,0,-1};
    int col[4]={1,0,-1,0};
    vector<int> exitPoint(vector<vector<int>>& mat) {
        // code here
        int n=mat.size(),m=mat[0].size();
        int i=0,j=0,k=0;
        vector<int>ans(2);
        while(i>=0 && i<n && j>=0 && j<m){
            ans[0]=i,ans[1]=j;
            if(mat[i][j]==1){
                mat[i][j]=0;
                k=(k+1)%4;
            }
            i+=row[k],j+=col[k];
        }
        return ans;
    }
};
