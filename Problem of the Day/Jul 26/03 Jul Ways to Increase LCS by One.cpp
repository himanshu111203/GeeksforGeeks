class Solution {
  public:
    int waysToIncreaseLCSBy1(string &s1, string &s2) {
        // code here
        int m=s1.size(),n=s2.size();
        vector<vector<int>>pref(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1])
                pref[i][j]=1+pref[i-1][j-1];
                else
                pref[i][j]=max(pref[i-1][j],pref[i][j-1]);
            }
        }
        int l=pref[m][n];
        vector<vector<int>>suff(m+1,vector<int>(n+1,0));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(s1[i]==s2[j])
                suff[i][j]=1+suff[i+1][j+1];
                else
                suff[i][j]=max(suff[i+1][j],suff[i][j+1]);
            }
        }
        int ans=0;
        for(int pos=0;pos<=m;pos++){
            for(char c='a';c<='z';c++){
                for(int j=0;j<n;j++){
                    if(s2[j]==c && pref[pos][j]+1+suff[pos][j+1]==l+1){
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
