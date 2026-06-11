class Solution {
  public:
    bool kSubstr(string &s, int k) {
        // code here
        int n=s.size();
        if(n%k!=0)
        return 0;
        unordered_map<string,int>m;
        for(int i=0;i<=n-k;i+=k){
            string temp=s.substr(i,k);
            m[temp]++;
        }
        if(m.size()>2)
        return 0;
        if(m.size()==1)
        return 1;
        for(auto i:m){
            if(i.second==1)
            return 1;
        }
        return 0;
    }
};
