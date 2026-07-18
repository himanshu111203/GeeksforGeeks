class Solution {
  public:
    const int mod=1e9+7;
    int findnextrow(vector<vector<int>>&suff,int r,int c,int m){
        int start=r+1,end=m,mid,ans=m,target=suff[r][c];
        while(start<=end){
            mid=start+(end-start)/2;
            if(suff[mid][c]<target){
                ans=mid;
                end=mid-1;
            }
            else
            start=mid+1;
        }
        return ans;
    }
    int findnextcol(vector<vector<int>>&suff,int r,int c,int n){
        int start=c+1,end=n,mid,ans=n,target=suff[r][c];
        while(start<=end){
            mid=start+(end-start)/2;
            if(suff[r][mid]<target){
                ans=mid;
                end=mid-1;
            }
            else
            start=mid+1;
        }
        return ans;
    }
    int findWays(vector<vector<int>>& matrix, int k) {
        // code here
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>>suff(m+1,vector<int>(n+1,0));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                suff[i][j]=matrix[i][j]+suff[i+1][j]+suff[i][j+1]-suff[i+1][j+1];
            }
        }
        vector<vector<vector<int>>>dp(k+1,vector<vector<int>>(m,vector<int>(n,0)));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(suff[i][j]>0)
                dp[1][i][j]=1;
            }
        }
        for(int rem=2; rem<=k;rem++){
            vector<vector<int>>dpSumRow(m+1,vector<int>(n,0)),
            dpSumCol(m,vector<int>(n+1,0));
            for(int r=m-1;r>=0;r--){
                for(int c=n-1;c>=0;c--){
                    dpSumRow[r][c]=(dp[rem-1][r][c]+dpSumRow[r+1][c])%mod;
                    dpSumCol[r][c]=(dp[rem-1][r][c]+dpSumCol[r][c+1])%mod;
                }
            }
            for(int r=0;r<m;r++){
                for(int c=0;c<n;c++){
                    if(suff[r][c]==0)
                    continue;
                    long long totalWays=0;
                    
                    int next_r=findnextrow(suff,r,c,m);
                    if (next_r<m)
                    totalWays=(totalWays+dpSumRow[next_r][c])%mod;
                    
                    int next_c=findnextcol(suff,r,c,n);
                    if (next_c<n) 
                    totalWays=(totalWays+dpSumCol[r][next_c])%mod;
                    
                    dp[rem][r][c]=totalWays;
                }
            }
        }
        return dp[k][0][0];
    }
};
