class Solution {
  public:
    int minComputation(vector<int> &files) {
        // code here
        priority_queue<int,vector<int>,greater<int>>q(files.begin(),files.end());
        int ans=0;
        while(q.size()>1){
            int a=q.top();
            q.pop();
            int b=q.top();
            q.pop();
            ans+=a+b;
            q.push(a+b);
        }
        return ans;
    }
};
