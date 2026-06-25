class Solution {
  public:
    void solve(int last,int len,int n,int num,vector<int>&ans){
        if(len==n){
            ans.push_back(num);
            return;
        }
        for(int i=last+1;i<10;i++)
        solve(i,len+1,n,num*10+i,ans);
    }
    vector<int> increasingNumbers(int n) {
        // code here
        vector<int>ans;
        if(n>10)
        return ans;
        if(n==1){
            for(int i=0;i<10;i++)
            ans.push_back(i);
            return ans;
        }
        for(int i=1;i<10;i++){
            solve(i,1,n,i,ans);
        }
        return ans;
    }
};
