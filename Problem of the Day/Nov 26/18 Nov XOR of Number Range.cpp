class Solution {
  public:
    int xorrange(int a){
        if(a%4==0) return a;
        else if(a%4==1) return 1;
        else if(a%4==2) return a+1;
        else 
        return 0;
    }
    int findXOR(int l, int r) {
        // code here
        return xorrange(l-1)^xorrange(r);
    }
};
