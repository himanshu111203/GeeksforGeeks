class Solution {
  public:
    int subsequenceSum(string &s) {
        // code here
        int n=s.size();
        const int mod=1e9+7;
        long long ans=0,p=1;
        for(int i=0;i<n;i++)
        ans+=(s[i]-'0');
        for(int i=0;i<n-1;i++)
        p=((p*2)%mod);
        return (ans*p)%mod;
    }
};
