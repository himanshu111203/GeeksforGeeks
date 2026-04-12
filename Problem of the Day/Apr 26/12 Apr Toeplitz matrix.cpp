class Solution {
  public:
    bool isToeplitz(vector<vector<int>>& mat) {
        // code here
        int m=mat.size(),n=mat[0].size();
        for(int i=0;i<m-1;i++){
            int x=mat[i][0];
            int a=i+1,b=1;
            while(a<m&& b<n){
                if(x!=mat[a][b])
                return 0;
                a++,b++;
            }
        }
        for(int j=1;j<n-1;j++){
            int x=mat[0][j];
            int a=1,b=j+1;
            while(a<m && b<n){
                if(x!=mat[a][b])
                return 0;
                a++,b++;
            }
        }
        return 1;
    }
};
