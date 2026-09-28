class Solution {
  public:
    int N;
    int row[8]={2,2,-2,-2,1,1,-1,-1};
    int col[8]={1,-1,1,-1,2,-2,2,-2};
    bool valid(int i,int j){
        return i>=0 && i<N && j>=0 && j<N;
    }
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        N=n;
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(N,vector<bool>(N,false));
        int si=knightPos[0]-1,sj=knightPos[1]-1,ti=targetPos[0]-1,tj=targetPos[1]-1;
        q.push({si,sj});
        vis[si][sj]=1;
        int steps=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                int i=q.front().first,j=q.front().second;
                q.pop();
                if(i==ti && j==tj)
                return steps;
                for(int k=0;k<8;k++){
                    int ni=i+row[k],nj=j+col[k];
                    if(valid(ni,nj) && !vis[ni][nj]){
                        q.push({ni,nj});
                        vis[ni][nj]=1;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
