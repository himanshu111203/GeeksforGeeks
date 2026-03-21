class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        int m = mat.size();
        int n = mat[0].size();
        queue <pair<int,int>> q;
        int count = 0;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (mat[i][j] == 2) {
                    q.push({i, j});
                } else if (mat[i][j] == 1) {
                    count += 1;
                }
            }
        }
        
        int days = 0;
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                pair <int,int> point = q.front();
                q.pop();
                int x = point.first;
                int y = point.second;
                if (x > 0 and mat[x-1][y] == 1) {
                    q.push({x - 1, y});
                    mat[x-1][y] = 2;
                    count -= 1;
                }
                if (y > 0 and mat[x][y-1] == 1) {
                    q.push({x, y - 1});
                    mat[x][y-1] = 2;
                    count -= 1;
                }
                if (x < m-1 and mat[x+1][y] == 1) {
                    q.push({x + 1, y});
                    mat[x+1][y] = 2;
                    count -= 1;
                }
                if (y < n-1 and mat[x][y+1] == 1) {
                    q.push({x, y + 1});
                    mat[x][y+1] = 2;
                    count -= 1;
                }
            }
            if (!q.empty()) days += 1;
            if (count == 0) break;
        }
        if (count != 0) return -1;
        return days;
    }
};
