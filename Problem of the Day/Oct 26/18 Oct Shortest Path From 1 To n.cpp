class Solution {
  public:
    int minimumStep(int n) {
        // code here
        int ans=0;
        while(n!=0){
            if(n%3==0)
            n/=3;
            else
            n--;
            ans++;
        }
        return ans-1;
    }
};
