class Solution {
  public:
    int solve(int n, string s) {
        // code here
        int ans=0,used=0;
        unordered_map<char,int>m;
        for(char ch:s){
            if(m.count(ch) && m[ch]==1){
                m[ch]=0;
                used--;
            }
            if(!m.count(ch)){
                m[ch]=1;
                used++;
                if(used>n){
                    ans++;
                    used=n;
                    m[ch]=0;
                }
            }
        }
        return ans;
    }
};
