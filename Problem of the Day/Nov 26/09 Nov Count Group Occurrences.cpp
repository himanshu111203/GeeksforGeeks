class Solution {
  public:
    int getCount(string &s, int k) {
        // code here
        vector<int>freq(26,0);
        int n=s.size(),i=0;
        while(i<n){
            freq[s[i]-'a']++;
            i++;
            while(i<n && s[i]==s[i-1])
            i++;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(freq[i]==k)
            ans++;
        }
        return ans;
    }
};
