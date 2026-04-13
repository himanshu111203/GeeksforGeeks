class Solution {
  public:
    string removeSpaces(string& s) {
        // code here
        int j=0,n=s.size();
        for(int i=0;i<s.size();i++){
            if(s[i]!=' ')
            swap(s[j++],s[i]);
        }
        j=n-1;
        while(j>=0 && s[j]==' '){
            s.pop_back();
            j--;
        }
        return s;
    }
};
