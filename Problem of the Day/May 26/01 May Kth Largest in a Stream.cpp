class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>>q;
        int n=arr.size();
        vector<int>ans(n,-1);
        for(int i=0;i<k;i++)
        q.push(arr[i]);
        ans[k-1]=q.top();
        for(int i=k;i<n;i++){
            if(q.top()<arr[i]){
                q.pop();
                q.push(arr[i]);
            }
            ans[i]=q.top();
        }
        return ans;
    }
};
