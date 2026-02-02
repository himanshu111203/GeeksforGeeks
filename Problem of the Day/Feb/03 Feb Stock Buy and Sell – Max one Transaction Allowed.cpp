class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int ans=0,mini=prices[0];
        for(int i:prices){
            if(i>mini)
            ans=max(ans,i-mini);
            else
            mini=i;
        }
        return ans;
    }
};
