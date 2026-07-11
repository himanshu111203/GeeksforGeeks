class Solution {
  public:
    int m,n;
    int row[4]={0,0,1,-1};
    int col[4]={1,-1,0,0};
    bool valid(int i,int j){
        return i>=0 && i<m && j>=0 && j<n;
    }
    int dfs(vector<vector<int>>&mat,int i,int j,int x,int y){
        if(i==x && j==y)
        return 0;
        if(!valid(i,j) || mat[i][j]==0)
        return -1;
        mat[i][j]=0;
        int maxpath=-1;
        for(int k=0;k<5;k++){
            int ni=i+row[k],nj=j+col[k];
            int pathlen=dfs(mat,ni,nj,x,y);
            if(pathlen!=-1)
            maxpath=max(maxpath,pathlen+1);
        }
        mat[i][j]=1;
        return maxpath;
    }
    int longestPath(vector<vector<int>>& mat, int xs, int ys, int xd, int yd) {
        // code here
        m=mat.size(),n=mat[0].size();
        if(mat[xs][ys]==0 || mat[xd][yd]==0)
        return -1;
        return dfs(mat,xs,ys,xd,yd);
    }
};
