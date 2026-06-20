class Solution {
  public:
    string chooseSwap(string &s) {
        // code here
        vector<int>first(26,-1);
        int n=s.size();
        for(int i=0;i<n;i++){
            if(first[s[i]-'a']==-1)
            first[s[i]-'a']=i;
        }
        for(int i=0;i<n;i++){
            for(char ch='a';ch<s[i];ch++){
                if(first[ch-'a']>i){
                    char ca1=s[i],c2=ch;
                    for(int j=0;j<n;j++){
                        if(s[j]==c1)
                        s[j]=c2;
                        else if(s[j]==c2)
                        s[j]=c1;
                    }
                    return s;
                }
            }
        }
        return s;
    }
};
