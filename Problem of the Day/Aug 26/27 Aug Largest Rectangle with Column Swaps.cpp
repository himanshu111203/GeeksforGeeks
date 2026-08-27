// T.C O(n*(n+m))
class Solution {
  public:
    int maxArea(vector<vector<int>>& mat) {
        // code here
        int n=mat.size(),m=mat[0].size();
        int ans=0;
        vector<int>arr(m,0);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1)
                arr[j]++;
                else
                arr[j]=0;
            }
            vector<int>freq(n+1,0);
            for(int j:arr)
            freq[j]++;
            int width=0;
            for(int h=n;h>=0;h--){
                width+=freq[h];
                ans=max(ans,h*width);
            }
        }
        return ans;
    }
};

// T.C O(n*m*log m)
class Solution {
  public:
    int maxArea(vector<vector<int>>& mat) {
        // code here
        int n=mat.size(),m=mat[0].size();
        int ans=0;
        vector<int>arr(m,0);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1)
                arr[j]++;
                else
                arr[j]=0;
            }
            vector<int>arr2=arr;
            sort(arr2.begin(),arr2.end());
            for(int j=m-1;j>=0;j--){
                ans=max(ans,arr2[j]*(m-j));
            }
        }
        return ans;
    }
};
