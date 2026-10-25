class Solution {
  public:
    typedef pair<int,int>p;
    int minDiff(int k, vector<int> &arr) {
        // code here
        int n=arr.size();
        priority_queue<p>maxi;
        priority_queue<p,vector<p>,greater<p>>mini;
        int ans=INT_MAX;
        for(int i=k;i<n;i++){
            maxi.push({arr[i],i});
            mini.push({arr[i],i});
        }
        ans=min(ans,maxi.top().first-mini.top().first);
        for(int i=0;i<n-k;i++){
            maxi.push({arr[i],i});
            mini.push({arr[i],i});
            while(!maxi.empty() && (maxi.top().second>=i+1 && maxi.top().second<=i+k))
            maxi.pop();
            while(!mini.empty() && (mini.top().second>=i+1 && mini.top().second<=i+k))
            mini.pop();
            ans=min(ans,maxi.top().first-mini.top().first);
        }
        return ans;
    }
};
