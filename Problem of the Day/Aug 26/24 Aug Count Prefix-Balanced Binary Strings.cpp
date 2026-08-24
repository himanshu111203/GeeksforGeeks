class Solution {
  public:
    const long long mod=1e9+7;
    long long power(long long a, long long b) {
        long long ans=1;
        while(b){
            if(b&1)
            ans=ans*a%mod;
            a=a*a%mod;
            b>>=1;
        }
        return ans;
    }
    int prefixStrings(int n) {
        // code here
        vector<long long>fact(2* n+1);
        fact[0]=1;
        for(int i=1;i<=2*n;i++)
        fact[i]=fact[i-1]*i%mod;
        long long invN=power(fact[n],mod-2);
        long long combination=fact[2*n]*invN%mod*invN%mod;
        long long inv=power(n+1,mod-2);
        return combination*inv%mod;
    }
};
