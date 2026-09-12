class Solution {
  public:
    int maxProduct(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        vector<vector<long long>>maxi(n+1,vector<long long>(k+1,LLONG_MIN)),mini(n+1,vector<long long>(k+1,LLONG_MAX));
        maxi[0][0]=mini[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=min(i,k);j++){
                maxi[i][j]=maxi[i-1][j];
                mini[i][j]=mini[i-1][j];
                if(j>0){
                    long long x=arr[i-1];
                    if(maxi[i-1][j-1]!=LLONG_MIN){
                        maxi[i][j]=max(maxi[i][j],
                        max(maxi[i-1][j-1]*x,mini[i-1][j-1]*x));
                        mini[i][j]=min(mini[i][j],
                        min(maxi[i-1][j-1]*x,mini[i-1][j-1]*x));
                    }
                }
            }
        }
        return maxi[n][k];
    }
};
