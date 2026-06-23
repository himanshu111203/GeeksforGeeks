class Solution {
  public:
    int maxPeopleDefeated(int p) {
        // Code Here
        int a=p;
        int c;
        for(c=1;c<=sqrt(p);c++){
            if(c*c<=a){
                a-=c*c;
            }else
            break;
        }
        return c-1;
    }
};
