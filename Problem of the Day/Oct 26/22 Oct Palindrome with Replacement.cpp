class Solution {
  public:
    int minimumSum(string &s) {
        // code here
        int n=s.size();
        int i=0,j=n-1;
        string temp="";
        while(i<j){
            if(s[i]!='?' && s[j]!='?' && s[i]!=s[j])
            return -1;
            if(s[i]!='?')
            temp+=s[i];
            else if(s[j]!='?')
            temp+=s[j];
            i++,j--;
        }
        int ans=0;
        i=1;
        while(i<temp.size()){
            ans+=abs(temp[i]-temp[i-1]);
            i++;
        }
        return 2*ans;
    }
};
