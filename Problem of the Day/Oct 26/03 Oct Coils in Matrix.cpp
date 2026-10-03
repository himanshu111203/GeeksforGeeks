class Solution {
  public:
    int m;
    int row[4]={1,0,-1,0};
    int col[4]={0,1,0,-1};
    bool valid(int i,int j,vector<vector<int>>&mat){
        return i>=0 && i<m && j>=0 && j<m && mat[i][j]!=-1;
    }
    vector<vector<int>> formCoils(int n) {
        // code here
        n*=4;
        int a=1;
        m=n;
        vector<vector<int>>mat(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j]=a;
                a++;
            }
        }
        int i=0,j=0,k=0;
        bool yes=1;
        vector<int>temp1,temp2;
        while(yes){
            temp1.push_back(mat[i][j]);
            mat[i][j]=-1;
            int ri=(m-1)-i,rj=(m-1)-j;
            temp2.push_back(mat[ri][rj]);
            mat[ri][rj]=-1;
            if(!valid(i+row[k],j+col[k],mat)){
                k=(k+1)%4;
                if(!valid(i+row[k],j+col[k],mat))
                yes=0;
            }
            i+=row[k],j+=col[k];
        }
        return {temp1,temp2};
    }
};
