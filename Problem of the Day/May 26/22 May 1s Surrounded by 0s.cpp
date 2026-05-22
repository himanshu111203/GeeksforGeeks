class Solution {
  public:
    int n,m;
    int row[4]={0,0,1,-1};
    int col[4]={1,-1,0,0};
    bool valid(int i,int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
    void dfs(int i,int j,vector<vector<int>>&grid,int &c){
        grid[i][j]=0;
        c++;
        for(int k=0;k<4;k++){
            int ni=i+row[k],nj=j+col[k];
            if(valid(ni,nj) && grid[ni][nj]==1)
            dfs(ni,nj,grid,c);
        }
    }
    int cntOnes(vector<vector<int>>& grid) {
        // code here
        n=grid.size(),m=grid[0].size();
        int x=0;
        for(int i=0;i<n;i++){
            if(i==0 || i==n-1){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==1)
                    dfs(i,j,grid,x);
                }
            }else{
                if(grid[i][0]==1)
                dfs(i,0,grid,x);
                if(grid[i][m-1]==1)
                dfs(i,m-1,grid,x);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int c=0;
                    dfs(i,j,grid,c);
                    ans+=c;;
                }
            }
        }
        return ans;
    }
};
