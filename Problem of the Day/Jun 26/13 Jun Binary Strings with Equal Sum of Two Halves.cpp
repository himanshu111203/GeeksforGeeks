class Solution {
  public:
    static const int mod=1000000007;
    using ll=long long;
    ll power(ll a,ll b){
        ll ans=1;
        while(b){
            if(b&1)
            ans=(ans*a)%mod;
            a=(a*a)%mod;
            b>>=1;
        }
        return ans;
    }
    int computeValue(int n) {
        // code here
        vector<ll>dp(2*n+1);
        dp[0]=1;
        for(int i=1;i<=2*n;i++)
        dp[i]=(dp[i-1]*i)%mod;
        ll den=(dp[n]*dp[n])%mod;
        return (dp[2*n]*power(den,mod-2))%mod;
    }
};
