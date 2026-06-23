class Solution {
  public:
    int maxPeopleDefeated(int p) {
        // Code Here
        long start=1,end=sqrt(p),mid,ans=0;
        while(start<=end){
            mid=start+(end-start)/2;
            long sum=(mid*(mid+1)*(2*mid+1)/6);
            if(sum<=p){
                ans=mid;
                start=mid+1;
            }else
            end=mid-1;
        }
        return (int)ans;
    }
};


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
