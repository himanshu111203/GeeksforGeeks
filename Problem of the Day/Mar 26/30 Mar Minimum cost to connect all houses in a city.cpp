class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        // code here
        int ans=0;
        int n=houses.size();
        vector<bool>vis(n,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int dis=it.first;
            if(!vis[it.second]){
            ans+=dis;
            vis[it.second]=true;}
            else
                continue;
            for(int i=0;i<n;i++){
                if(vis[i]==0){
                    int d=abs(houses[it.second][0]-houses[i][0])+abs(houses[it.second][1]-houses[i][1]);
                    pq.push({d,i});
                }
            }
        }
        return ans;
    }
};
