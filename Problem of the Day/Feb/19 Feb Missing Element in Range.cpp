class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // code here
        vector<bool>present(high-low+1,0);
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=low && arr[i]<=high)
            present[arr[i]-low]=1;
        }
        vector<int>ans;
        for(int i=0;i<present.size();i++){
            if(!present[i])
            ans.push_back(i+low);
        }
        return ans;
    }
};
