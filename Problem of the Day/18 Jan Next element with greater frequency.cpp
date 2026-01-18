class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        // code here
        unordered_map<int,int>m;
        for(int i:arr){
            m[i]++;
        }
        int n=arr.size();
        vector<int>ans(n,-1);
        stack<int>s;
        s.push(arr[n-1]);
        for(int i=n-2;i>=0;i--){
            int a=arr[i];
            while(!s.empty() && m[a]>=m[s.top()])
            s.pop();
            if(!s.empty()) ans[i]=s.top();
            s.push(a);
        }
        return ans;
    }
};
