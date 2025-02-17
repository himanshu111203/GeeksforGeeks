class Solution {
  public:
    // Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(vector<int>& arr) {
        vector<int>ans;
        stack<pair<int,int>>s;
        for(int i=0;i<arr.size();i++){
            int c=1;
            while(!s.empty() && s.top().first<=arr[i]){
                c+=s.top().second;
                s.pop();
            }
            s.push({arr[i],c});
            ans.push_back(c);
        }
        return ans;
        
    }
};
