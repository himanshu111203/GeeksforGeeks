class Solution {
  public:
    string minWindow(string &s, string &p) {
        // code here
        int n=s.size(),m=p.size(),l=0,size=INT_MAX,ind=-1;
        if(m>n) return "";
        unordered_map<char,int>mp;
        for(char a:p)
        mp[a]++;
        for(int r=0;r<n;r++){
            if(mp[s[r]]>0) 
            m--;
            mp[s[r]]--;
            while(l<n && m==0){
                int currsize=r-l+1;
                if(currsize<size){
                    size=currsize;
                    ind=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0)
                m++;
                l++;
            }
        }
        return size==INT_MAX ? "" : s.substr(ind,size);
    }
};
