class Solution {
  public:
    bool isSumOfConsecutive(int n) {
        // code here
        // Every number that is NOT a power of 2 can be expressed as consecutive numbers.
        if(n==1)
        return 0;
        while(n>1){
            if(n%2)
            return 1;
            n=n/2;
        }
        return 0;
    }
};
