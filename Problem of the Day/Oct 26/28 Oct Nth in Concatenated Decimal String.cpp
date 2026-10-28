class Solution {
  public:
    char nthCharacter(int n) {
        long long len=1,c=9,start=1;
        while(n>len*c){
            n-=len*c;
            len++;
            c*=10;
            start*=10;
        }
        long long num=start+(n-1)/len;
        string str=to_string(num);
        int ind=(n-1)%len;
        return str[ind];
    }
};
