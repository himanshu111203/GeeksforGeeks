class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        // code here
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        if(s1.size()!=s2.size()) return 0;
        for(int i=0;i<s1.size();i++){
            if(m1.find(s1[i])==m1.end())
            m1[s1[i]]=i;
            if(m2.find(s2[i])==m2.end())
            m2[s2[i]]=i;
            if(m1[s1[i]]!=m2[s2[i]])
            return 0;
        }
        return 1;
    }
};
