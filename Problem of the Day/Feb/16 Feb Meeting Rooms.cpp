class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            if(arr[i][1]>arr[i+1][0])
            return 0;
        }
        return 1;
    }
};
