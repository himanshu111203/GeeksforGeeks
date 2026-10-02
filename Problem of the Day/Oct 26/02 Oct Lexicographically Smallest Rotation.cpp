class Solution {
  public:
    string lexiString(string &s) {
        // code here
        string str=s+s;
        int n=str.size();
        vector<int>f(n,-1);
        int k=0;
        for(int j=1;j<n;j++){
            char ch=str[j];
            int i=f[j-k-1];
            while(i!=-1 && ch!=str[k+i+1]){
                if(ch<str[k+i+1])
                k=j-i-1;
                i=f[i];
            }
            if(ch!=str[k+i+1]){
                if(ch<str[k])
                k=j;
                f[j-k]=-1;
            }else
            f[j-k]=i+1;
        }
        return str.substr(k,n/2);
    }
};
