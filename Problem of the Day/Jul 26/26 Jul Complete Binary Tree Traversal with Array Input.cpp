class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        // code here
        vector<vector<int>>ans;
        int i=0,n=arr.size(),j=1;
        while(i<n){
            int k=j;
            vector<int>temp;
            while(i<n && k){
                temp.push_back(arr[i++]);
                k--;
            }
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
            j*=2;
        }
        return ans;
    }
};
