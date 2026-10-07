class Solution{
public:
    int n,m;
    int row[4]={0,0,1,-1};
    int col[4]={1,-1,0,0};
    vector<vector<int>>dp;
    bool valid(int i,int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
    int solve(int i,int j,vector<vector<int>>&matrix){
        if(dp[i][j]!=-1)
        return dp[i][j];
        int ans=1;
        for(int k=0;k<4;k++){
            int ni=i+row[k],nj=j+col[k];
            if(valid(ni,nj) && matrix[ni][nj]>matrix[i][j])
            ans=max(ans,1+solve(ni,nj,matrix));
        }
        return dp[i][j]=ans;
    }

    int longIncPath(vector<vector<int>>&matrix,int n,int m){
        this->n=n,this->m=m;
        dp.assign(n,vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            ans=max(ans,solve(i,j,matrix));
        }
        return ans;
    }
};
