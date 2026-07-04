class Solution {
  public:
    int maxCharGap(string &s) {
        // code here
        vector<int>occur(26,-1);
        int ans=-1,n=s.size();
        for(int i=0;i<n;i++){
            if(occur[s[i]-'a']==-1)
            occur[s[i]-'a']=i;
            else
            ans=max(ans,i-occur[s[i]-'a']-1);
        }
        return ans;
    }
};
