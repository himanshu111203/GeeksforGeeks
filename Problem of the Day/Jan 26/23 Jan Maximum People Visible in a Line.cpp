class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>ngr(n,n);
        vector<int>ngl(n,-1);
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]<arr[i])
            s.pop();
            if(!s.empty())
            ngr[i]=s.top();
            s.push(i);
        }
        while(!s.empty()) 
        s.pop();
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]<arr[i])
            s.pop();
            if(!s.empty())
            ngl[i]=s.top();
            s.push(i);
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,ngr[i]-ngl[i]-1);
        }
        return ans;
    }
};
