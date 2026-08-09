//Top Down
class Solution {
  public:
    int n;
    vector<vector<int>>dp;
    int solve(int i,vector<int>&h,vector<int>&l,bool canhigh){
        if(i==n)
        return 0;
        if(dp[i][canhigh]!=-1)
        return dp[i][canhigh];
        int notask=solve(i+1,h,l,1);
        int high=0;
        if(canhigh)
        high=h[i]+solve(i+1,h,l,0);
        int low=l[i]+solve(i+1,h,l,0);
        return dp[i][canhigh]=max({notask,high,low});
    }
    int maxTask(vector<int>& h, vector<int>& l) {
        // code here
        n=h.size();
        dp.assign(n+1,vector<int>(2,-1));
        return solve(0,h,l,1);
    }
};

//Bottom Up
class Solution {
  public:
    int maxTask(vector<int>& h, vector<int>& l) {
        // code here
        int n=h.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                int no=dp[i+1][1];
                int high=0;
                if(j==1)
                high=h[i]+dp[i+1][0];
                int low=l[i]+dp[i+1][0];
                dp[i][j]=max({no,high,low});
            }
        }
        return dp[0][1];
    }
};

//Bottom Up
class Solution {
  public:
    int maxTask(vector<int>& h, vector<int>& l) {
        // code here
        int n=h.size();
        vector<int>dp(n);
        dp[0]=max(h[0],l[0]);
        if(n>1)
        dp[1]=max(h[1],l[1]+dp[0]);
        for(int i=2;i<n;i++)
        dp[i]=max(h[i]+dp[i-2],l[i]+dp[i-1]);
        return dp[n-1];
    }
};

//Space optimized
class Solution {
  public:
    int maxTask(vector<int>& h, vector<int>& l) {
        // code here
        int n=h.size();
        int prev2=max(h[0],l[0]);
        if(n==1)
        return prev2;
        int prev=max(h[1],l[1]+prev2);
        for(int i=2;i<n;i++){
            int curr=max(h[i]+prev2,l[i]+prev);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};
