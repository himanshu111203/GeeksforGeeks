class Solution {
  public:
    bool isBinaryPalindrome(int n) {
        // code here
        string a="";
        while(n){
            char b=(n%2)+'0';
            a+=b;
            n/=2;
        }
        int i=0,j=a.size()-1;
        while(i<j){
            if(a[i]!=a[j])
            return 0;
            i++,j--;
        }
        return 1;
    }
};
