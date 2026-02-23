class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        vector<int>ans;
        unordered_set<int>s;
        for(int i:a)
        s.insert(i);
        for(int i:b)
        s.insert(i);
        for(int i:s)
        ans.push_back(i);
        return ans;
    }
};
