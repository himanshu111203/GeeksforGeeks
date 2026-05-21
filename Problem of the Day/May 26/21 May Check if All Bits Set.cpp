class Solution {
  public:
    bool isBitSet(int n) {
        // code here
        if(n==0) return 0;
        return (n&(n+1))==0;
    }
};
