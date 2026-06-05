class Solution {
  public:
    int numOfWays(int n, int m) {
        // code here
        long long total=(long long)(n*m)*(n*m-1);
        long long attacks=0;
        int dx[]={1,2,2,1};
        int dy[]={2,1,-1,-2};
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int k=0;k<4;k++)
                {
                    int ni=i+dx[k];
                    int nj=j+dy[k];
                    if(ni>=0 && ni<n && nj>=0 && nj<m)
                    {
                        attacks++;
                    }
                }
            }
        }
        return (int)(total-attacks*2);
    }
};
