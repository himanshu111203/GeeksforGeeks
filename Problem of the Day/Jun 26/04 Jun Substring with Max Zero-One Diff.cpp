class Solution {
  public:
    int maxSubstring(string &s) {
        // code here
        int ans=INT_MIN,sum=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0')
            sum++;
            else
            sum--;
            ans=max(ans,sum);
            if(sum<0)
            sum=0;
        }
        return ans<=0 ? -1:ans;
    }
};
