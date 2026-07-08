class Solution {
  public:
    int row[4]={0,0,1,-1};
    int col[4]={1,-1,0,0};
    int n,m;
    bool valid(int i,int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
    void dfs(int i,int j,vector<vector<int>>&mat,vector<vector<bool>>&vis){
        vis[i][j]=1;
        for (int k=0;k<4;k++) {
            int ni=i+row[k],nj=j+col[k];
            if(valid(ni,nj) && !vis[ni][nj] && mat[ni][nj]>=mat[i][j])
            dfs(ni,nj,mat,vis);
        }
    }
    int countCoordinates(vector<vector<int>>& mat) {
        // code here
        n=mat.size(),m=mat[0].size();
        vector<vector<bool>>sp(n,vector<bool>(m,0)),sq(n,vector<bool>(m,0));
        for(int j=0;j<m;j++){
            if(!sp[0][j])
            dfs(0,j,mat,sp);
        }
        for(int i=0;i<n;i++){
            if(!sp[i][0])
            dfs(i,0,mat,sp);
        }
        for(int j=0;j<m;j++){
            if(!sq[n-1][j])
            dfs(n-1,j,mat,sq);
        }
        for(int i=0;i<n;i++){
            if(!sq[i][m-1])
            dfs(i,m-1,mat,sq);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(sp[i][j] && sq[i][j])
                ans++;
            }
        }
        return ans;
    }
};
