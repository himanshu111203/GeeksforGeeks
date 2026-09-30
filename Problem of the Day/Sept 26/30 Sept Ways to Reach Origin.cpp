class Solution {
  public:
    int ways(int x, int y) {
        // code here
        const int mod=1e9+7;
        vector<vector<int>>mat(x+1,vector<int>(y+1,1));
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++)
            mat[i][j]=(1LL*(mat[i-1][j]+mat[i][j-1]))%mod;
        }
        return mat[x][y];
    }
};
