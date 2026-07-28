class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        // code here
        unordered_set<int>s;
        for(int i:arr)
        s.insert(i);
        int ans=0;
        for(int i:arr){
            if(!s.count(i-1)){
                ans++;
            }
        }
        return ans;
    }
};
