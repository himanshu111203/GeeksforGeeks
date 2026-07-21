class Solution {
  public:
    int maxIndexDifference(string &s) {
        // code here
        int n=s.size();

        vector<int>dp(n),best(26,-1);

        for (int i=n-1;i>=0;i--){
            int c=s[i]-'a';
            dp[i]=i;
            if(c<25 && best[c+1]!=-1)
            dp[i]=best[c+1];
            best[c]=max(best[c],dp[i]);
        }

        int ans=-1;
        bool found=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                found=1;
                ans=max(ans,dp[i]-i);
            }
        }
        return found ? ans : -1;
    }
};
