class Solution {
  public:
    int largestArea(int n, int m, vector<vector<int>> &arr) {
        // code here
        vector<int>row,col;
        int k=arr.size();
        if(k==0)
        return n*m;
        for(int i=0;i<k;i++){
            row.push_back(arr[i][0]);
            col.push_back(arr[i][1]);
        }
        sort(row.begin(),row.end());
        sort(col.begin(),col.end());
        int maxr=max(row[0]-1,n-row[k-1]);
        int maxc=max(col[0]-1,m-col[k-1]);
        for(int i=1;i<k;i++){
            maxr=max(maxr,row[i]-row[i-1]-1);
            maxc=max(maxc,col[i]-col[i-1]-1);
        }
        return maxr*maxc;
    }
};
