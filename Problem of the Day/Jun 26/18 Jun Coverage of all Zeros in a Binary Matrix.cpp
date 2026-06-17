class Solution {
  public:
    int findCoverage(vector<vector<int>>& mat) {
        // code here
        int m=mat.size(),n=mat[0].size(),ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    //left
                    for(int k=j-1;k>=0;k--){
                        if(mat[i][k]==1){
                            ans++;
                            break;
                        }
                    }
                    //right
                    for(int k=j+1;k<n;k++){
                        if(mat[i][k]==1){
                            ans++;
                            break;
                        }
                    }
                    //up
                    for(int k=i-1;k>=0;k--){
                        if(mat[k][j]==1){
                            ans++;
                            break;
                        }
                    }
                    //down
                    for(int k=i+1;k<m;k++){
                        if(mat[k][j]==1){
                            ans++;
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
