class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        // code here
        vector<int>ans;
        int n=mat.size();
        for(int j=0;j<n;j++){
            int a=0,b=j;
            while(b>=0){
                ans.push_back(mat[a++][b--]);
            }
        }
        for(int i=1;i<n;i++){
            int a=i,b=n-1;
            while(a<n){
                ans.push_back(mat[a++][b--]);
            }
        }
        return ans;
    }
};
