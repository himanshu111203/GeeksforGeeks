class Solution {
  public:
    int n,m;
    int row[8]={0,0,1,-1,1,1,-1,-1};
    int col[8]={1,-1,0,0,1,-1,1,-1};
    bool valid(int i,int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
    bool find(int i,int j,int ind,int d,vector<vector<char>> &mat, string &word){
        if(ind==word.size())
        return 1;
        if(!valid(i,j) || mat[i][j]!=word[ind])
        return 0;
        return find(i+row[d],j+col[d],ind+1,d,mat,word);
    }
    vector<vector<int>> searchWord(vector<vector<char>> &mat, string &word) {
        // Code here
        vector<vector<int>>ans;
        n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]!=word[0])
                continue;
                for(int d=0;d<8;d++){
                    if(find(i,j,0,d,mat,word)){
                        ans.push_back({i,j});
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
