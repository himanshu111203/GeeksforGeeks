class Solution {
  public:
    int findPosition(int n) {
        // code here
        if((n&n-1)!=0) // tell it is powers of 2 or not(which have only one set bit)
        return -1;
        return (int)log2(n)+1; ////returns the position if it have only set bit pos
    }
};
