class Solution {
  public:
    int findIndex(string &s) {
        // code here
        int o=0,c=0;
        for(char ch:s){
            if(ch==')')
            c++;
        }
        int n=s.size();
        for(int i=0;i<n;i++){
            if(o==c)
            return i;
            if(s[i]=='(')
            o++;
            else
            c--;
        }
        return n;
    }
};
