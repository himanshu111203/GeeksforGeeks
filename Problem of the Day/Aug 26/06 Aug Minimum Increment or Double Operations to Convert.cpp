class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
        // code here
        int ans=0;
        while(1){
            bool yes=1;
            for(int &i:arr){
                if(i%2==1){
                    i--;
                    ans++;
                }
                if(i>0)
                yes=0;
            }
            if(yes)
            break;
            for(int &i:arr)
            i/=2;
            ans++;
        }
        return ans;
    }
};
