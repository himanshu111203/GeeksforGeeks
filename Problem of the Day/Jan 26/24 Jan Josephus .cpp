class Solution {
  public:
  int winner(int n,int k){
      if(n==1)
      return 0;
      return (winner(n-1,k)+k)%n;
  }
    int josephus(int n, int k) {
        // code here
        return winner(n,k)+1;
    }
};
