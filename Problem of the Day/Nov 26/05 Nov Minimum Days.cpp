class Solution {
  public:
    int getMinimumDays(string &s, vector<int> &p) {
        // code here
        int ans=0,n=p.size();
        for(int i=0;i<n;i++){
            int ind=p[i];
            char r=(ind+1<n)?s[ind+1]:'$';
            char l=(ind-1>=0)?s[ind-1]:'$';
            if(r==s[ind] || l==s[ind]){
                s[ind]='?';
                ans=i+1;
            }
        }
        return ans;
    }
};
