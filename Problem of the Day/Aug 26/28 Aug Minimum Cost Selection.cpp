class Solution {
  public:
    int minCost(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<3;j++)
            mat[i][j]+=min(mat[i+1][(j+1)%3],mat[i+1][(j+2)%3]);
        }
        return min({mat[0][0],mat[0][1],mat[0][2]});
    }
};
