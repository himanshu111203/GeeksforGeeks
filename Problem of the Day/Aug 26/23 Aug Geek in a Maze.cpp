class Solution {
  public:
    int n,m;
    int row[4]={1,-1,0,0};
    int col[4]={0,0,1,-1};
    bool valid(int i,int j){
        return i>=0 && i<n  && j>=0 && j<m;
    }
    int numberOfCells(int r, int c, int u, int d, vector<vector<char>> &mat) {
        // code here
        n=mat.size(),m=mat[0].size();
        if(mat[r][c]=='#')
        return 0;
        vector<vector<int>>best(n,vector<int>(m,-1));
        queue<pair<pair<int,int>,pair<int,int>>>q;
        q.push({{r,c},{u,d}});
        mat[r][c]='#';
        best[r][c]=u;
        int ans=1;
        while(!q.empty()){
            int i=q.front().first.first,j=q.front().first.second;
            int up=q.front().second.first,down=q.front().second.second;
            q.pop();
            for(int k=0;k<4;k++){
                if((k==0 && down==0) || (k==1 && up==0))
                continue;
                int ni=i+row[k],nj=j+col[k];
                if(!valid(ni,nj) || mat[ni][nj]=='#')
                continue;
                int newup=up,newdown=down;
                if(k==0)
                newdown--;
                if(k==1)
                newup--;
                if(best[ni][nj] < newup){
                    if(best[ni][nj]==-1)
                    ans++;
                    best[ni][nj]=newup;
                    q.push({{ni,nj},{newup,newdown}});
                }
            }
        }
        return ans;
    }
};
