class Solution {
  public:
    string findLongestWord(string &s, vector<string> &d) {
        // code here
        int n=s.size();
        vector<vector<int>>pos(26);
        for(int i=0;i<n;i++)
        pos[s[i]-'a'].push_back(i);
        string ans="";
        for(string &temp:d){
            int prev=-1;
            bool ok=true;
            for(char c:temp){
                auto &v=pos[c-'a'];
                auto it=upper_bound(v.begin(),v.end(),prev);
                if(it==v.end()){
                    ok=false;
                    break;
                }
                prev=*it;
            }
            if(ok&&(temp.size()>ans.size()||(temp.size()==ans.size()&&temp<ans)))
            ans=temp;
        }
        return ans;
    }
};
