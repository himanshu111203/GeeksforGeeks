class Solution {
  public:
    int minSquares(int n, int m) {
        // code here
        int ans=0;
        while(n>0 && m>0){
            if(n>m)
            swap(n,m);
            ans+=m/n;
            m=m%n;
            swap(n,m);
        }
        return ans;
    }
};
