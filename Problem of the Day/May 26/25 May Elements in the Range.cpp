class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        // code here
        int n=end-start+1;
        vector<bool>vis(n,0);
        for(int i:arr){
            if(i>=start && i<=end){
                if(vis[i-start])
                return 0;
                vis[i-start]=1;
            }
        }
        for(bool i:vis){
            if(!i)
            return 0;
        }
        return 1;
    }
};
