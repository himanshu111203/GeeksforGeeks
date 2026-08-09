class Solution {
  public:
    int zigzagSequence(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int temp=INT_MIN;
                for(int k=0;k<n;k++){
                    if(k!=j)
                    temp=max(temp,mat[i-1][k]);
                }
                mat[i][j]+=temp;
            }
        }
        int ans=INT_MIN;
        for(int j=0;j<n;j++)
        ans=max(ans,mat[n-1][j]);
        return ans;
    }
};
