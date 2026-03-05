class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int l=0,n=s.size(),ans=-1;
        unordered_map<char,int>m;
        for(int r=0;r<n;r++){
            m[s[r]]++;
            if(m[s[r]]==1)
            k--;
            while(k<0){
                if(m[s[l]]==1)
                k++;
                m[s[l++]]--;
            }
            if(k==0)
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
