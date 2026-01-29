class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        vector<int>freq(26, 0);
        queue<char>q;
        string ans="";
        for (char ch:s){
            freq[ch-'a']++;
            q.push(ch);
            while(!q.empty() && freq[q.front()-'a']>1){
                q.pop();
            }
            if(q.empty())
            ans.push_back('#');
            else
            ans.push_back(q.front());
        }
        return ans;
    }
};
