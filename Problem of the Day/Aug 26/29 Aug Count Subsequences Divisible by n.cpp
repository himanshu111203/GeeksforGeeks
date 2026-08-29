class Solution {
  public: 
    const int mod=1e9+7;
    int m;
    vector<vector<int>>dp;
    int solve(int i,string &s,int divisor,int rem){
        if(i==m)
        return rem==0;
        if(dp[i][rem]!=-1)
        return dp[i][rem];
        int num=s[i]-'0';
        int newrem=(rem*10+num)%divisor;
        int take=solve(i+1,s,divisor,newrem);
        int skip=solve(i+1,s,divisor,rem);
        return dp[i][rem]=(take+skip)%mod;
    }
    int countSubsequences(string& s, int n) {
        // code here
        m=s.size();
        dp.assign(m+1,vector<int>(n+1,-1));
        return solve(0,s,n,0)-1;
    }
};
