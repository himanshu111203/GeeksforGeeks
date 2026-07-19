class Solution {
  public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        int n=arr.size();
        vector<int>left(n),right(n);
        int l=0,r=n-1;
        left[0]=0;
        right[n-1]=n-1;
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1])
            l=i;
            left[i]=l;
        }
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1])
            r=i;
            right[i]=r;
        }
        vector<bool>ans;
        for(auto &q:queries){
            int l=q[0],r=q[1];
            if(right[l]>=left[r])
            ans.push_back(1);
            else
            ans.push_back(0);
        }
        return ans;
    }
};
