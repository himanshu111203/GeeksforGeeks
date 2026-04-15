class Solution {
  public:
    int myAtoi(string &s) {
        // code here
        int sign=1;
        int i=0;
        while(s[i]==' ')
        i++;
        if(s[i]=='-'){
            i++;
            sign=-1;
        }
        if(s[i]=='+'){
            i++;
        }
        long temp=0;
        while((s[i]-'0')>=0 && (s[i]-'0')<=9){
            temp=temp*10+(s[i]-'0');
            if(sign*temp>=INT_MAX) return INT_MAX;
            if(sign*temp<=INT_MIN) return INT_MIN;
            i++;
        }
        return sign*temp;
    }
};
