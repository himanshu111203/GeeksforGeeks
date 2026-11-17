class Solution {
  public:
    bool findPattern(string& s) {
        // code here
        int cnt=0,n=s.size(),i=0;
        while(i<n){
            while(i<n && s[i]=='x')
            i++,cnt++;
            while(i<n && s[i]=='y')
            i++,cnt--;
            if(cnt<0 || cnt>0)
            return 0;
        }
        return cnt==0?1:0;
    }
};
