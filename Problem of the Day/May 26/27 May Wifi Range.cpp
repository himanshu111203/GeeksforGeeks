class Solution {
  public:
    bool wifiRange(string &s, int x) {
        // code here
        int n=s.size();
        int i=0;
        while(i<n){
            if(s[i]=='1'){
                int temp=i;
                i++;
                while(i<=temp+x&&i<n){
                    if(s[i]!='1'){
                        s[i]='c';
                        i++;
                    }
                    else{
                        break;
                    }
                }
            }
            else{
                i++;
            }
        }
        int j=n-1;
        while(j>=0){
            if(s[j]=='1'){
                int temp=j;
                j--;
                while(j>=temp-x&&j>=0){
                    if(s[j]!='1'){
                        s[j]='c';
                        j--;
                    }
                    else{
                        break;
                    }
                }
            }
            else{
                j--;
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                return false;
            }
        }
        return true;
    }
};
