class Solution {
  public:
    int beautySum(string &s) {
        // code here
        int n=s.size(),ans=0;
        for(int i=0;i<n;i++){
            vector<int>freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                int mini=INT_MAX,maxi=INT_MIN;
                for(int k:freq){
                    if(k!=0){
                        mini=min(mini,k);
                        maxi=max(maxi,k);
                    }
                }
                ans+=(maxi-mini);
            }
        }
        return ans;
    }
};
