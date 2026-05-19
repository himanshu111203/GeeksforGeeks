class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        vector<bool>visited(1000,0);
        queue<pair<int,int>>q;
        q.push({start,0});
        while(!q.empty()){
            int val=q.front().first;
            int count=q.front().second;
            q.pop();
            if(val==end)
            return count;
            for(int i:arr){
                int prod=(i*val)%1000;
                if(!visited[prod]){
                    visited[prod]=1;
                    q.push({prod,count+1});
                }
            }
        }
        return -1;
    }
};
