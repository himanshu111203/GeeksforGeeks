class Solution {
  public:
    int findPerimeter(vector<vector<int>> &mat) {
        // code here
        int n=mat.size(),m=mat[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    ans+=4;
                    if(i>0 && mat[i-1][j]==1)
                    ans-=2;
                    if(j>0 && mat[i][j-1]==1)
                    ans-=2;
                }
            }
        }
        return ans;
    }
};
