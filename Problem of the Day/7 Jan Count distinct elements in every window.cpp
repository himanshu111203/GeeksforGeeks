class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int>m;
        vector<int>ans;
        int a=0;
        for(int i=0;i<k;i++){
            m[arr[i]]++;
            if(m[arr[i]]==1)
            a++;
        }
        ans.push_back(a);
        for(int i=k;i<arr.size();i++){
            if(m[arr[i-k]]==1)
            a--;
            m[arr[i-k]]--;
            m[arr[i]]++;
            if(m[arr[i]]==1)
            a++;
            ans.push_back(a);
        }
        return ans;
    }
};
