class Solution {
  public:
    int n,m;
    int row[4]={1,-1,0,0};
    int col[4]={0,0,1,-1};
    bool valid(int i,int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
    int shortestPath(vector<vector<int>> &mat) {
        // code here
        n=mat.size(),m=mat[0].size();
		int result=1e9;
		vector<vector<int>>dist(n,vector<int>(m,1e9));
		queue<pair<int,int>>q;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(mat[i][j]==0){
					dist[i][j]=-1e9;
					for(int k=0;k<4;k++){
						int ni=i+row[k],nj=j+col[k];
						if(valid(ni,nj))
						dist[ni][nj]=-1e9;
					}
				}
			}
		}
		for (int i=0;i<n;i++){
			if(mat[i][0]==1 && dist[i][0]==1e9){
				q.push({i,0});
				dist[i][0]=1;
			}
		}
		while(!q.empty()){
			int i=q.front().first,j=q.front().second;
			q.pop();
			if(j==m-1)
			result=min(result,dist[i][j]);
			for(int k=0;k<4;k++) {
				int ni= i+row[k],nj=j+col[k];
				if(valid(ni,nj)){
					if(dist[i][j]+1<dist[ni][nj]){
						dist[ni][nj]=dist[i][j]+1;
						q.push({ni,nj});
					}
				}
			}
		}
		return (result==1e9)?-1:result;
    }
};
