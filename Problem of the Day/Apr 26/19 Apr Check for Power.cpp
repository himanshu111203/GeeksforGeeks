class Solution {
  public:
    bool isPower(int x, int y) {
        // code here
        if(x==1)
        return 0;
        while(y!=1){
            if(y%x!=0)
            return 0;
            y/=x;
        }
        return 1;
    }
};
