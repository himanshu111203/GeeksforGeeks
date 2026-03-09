class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>nse(n,-1);
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[i]<arr[s.top()]){
                nse[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(nse[i]==-1)
            ans+=n-i;
            else
            ans+=nse[i]-i;
        }
        return ans;
    }
};
