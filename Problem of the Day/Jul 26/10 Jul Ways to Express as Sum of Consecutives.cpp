class Solution {
  public:
    int getCount(int n) {
        // code here
        while(n%2==0)
        n/=2;
        int divcount=0;
        for(int i=1;1LL*i*i<=n;i++){
            if(n%i==0){
                if(1LL*i*i==n)
                divcount++;
                else
                divcount+=2;
            }
        }
        return divcount-1;
    }
};
