class Solution {
  public:
    int maxAmount(vector<int>& arr, int k) {
        // code here
        priority_queue<int>q(arr.begin(),arr.end());
        int ans=0;
        const int mod=1e9+7;
        while(!q.empty() && k){
            int temp=q.top();
            q.pop();
            ans=(ans+temp)%mod;
            temp--;
            if(temp>0)
            q.push(temp);
            k--;
        }
        return ans;
    }
};
