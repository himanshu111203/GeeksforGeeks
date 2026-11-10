class Solution {
  public:
    bool checkWithinK(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            if(m.count(arr[i]) && m[arr[i]]>=i-k)
            return 1;
            m[arr[i]]=i;
        }
        return 0;
    }
};
