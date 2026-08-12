class Solution {
  public:
    vector<int> findWays(vector<vector<int>>& grid) {
        // code here
        const int mod=1e9+7;
        int n=grid.size();
        vector<vector<int>>arr(n,vector<int>(n,0)),arr2(n,vector<int>(n,0));
        arr[n-1][n-1]=1,arr2[n-1][n-1]=grid[n-1][n-1];
        int i=n-1,j=n-2;
        while(j>=0 && grid[i][j]!=2){
            arr[i][j]=1;
            arr2[i][j]=grid[i][j]+arr2[i][j+1];
            j--;
        }
        i=n-2,j=n-1;
        while(i>=0 && grid[i][j]!=1){
            arr[i][j]=1;
            arr2[i][j]=grid[i][j]+arr2[i+1][j];
            i--;
        }
        for(int i=n-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                if(grid[i][j]==1){
                    arr[i][j]=arr[i][j+1];
                    if(arr[i][j+1]!=0)
                    arr2[i][j]=grid[i][j]+arr2[i][j+1];
                }else if(grid[i][j]==2){
                    arr[i][j]=arr[i+1][j];
                    if(arr[i+1][j]!=0)
                    arr2[i][j]=grid[i][j]+arr2[i+1][j];
                }else{
                    arr[i][j]=((long long)arr[i+1][j]+arr[i][j+1])%mod;
                    if(arr[i][j+1]!=0 || arr[i+1][j]!=0) 
                    arr2[i][j]=grid[i][j]+max(arr2[i][j+1],arr2[i+1][j]);
                }
            }
        }
        return {arr[0][0],arr2[0][0]};
    }
};
