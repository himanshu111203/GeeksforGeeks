class Solution {
  public:
  int row[4]={-1,1,0,0};
  int col[4]={0,0,-1,1};
  int m,n;
  bool valid(int i,int j){
      return i>=0 && i<m && j>=0 && j<n;
  }
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        m=mat.size(),n=mat[0].size();
        queue<pair<int,int>>q;
        int count=0,ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==2)
                q.push({i,j});
                else if(mat[i][j]==1)
                count++;
            }
        }
        while(!q.empty()){
            int len=q.size();
            while(len--){
                auto it=q.front();
                q.pop();
                int i=it.first,j=it.second;
                for(int k=0;k<4;k++){
                    if(valid(i+row[k],j+col[k]) && mat[i+row[k]][j+col[k]]==1){
                        q.push({i+row[k],j+col[k]});
                        mat[i+row[k]][j+col[k]]=2;
                        count--;
                    }
                }
            }
            if(!q.empty()) 
            ans++;
            if(count==0) break;
        }
        return count==0 ?ans :-1;
    }
};
