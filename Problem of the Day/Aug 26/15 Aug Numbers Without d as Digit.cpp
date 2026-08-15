class Solution {
  public:
    int f(int i, int t, int c, int m, int &d, vector<int> &digits, vector<vector<vector<int>>> &dp) {
        if(i == m) return c;
        if(dp[i][t][c] != -1) return dp[i][t][c];
        int ans = 0;
        for(int k = 0; k < 10; k++) {
            if((k != 0 || c != 0) && ((k == d) || (t == 0 && k > digits[i]))) continue;
            ans += f(i + 1, t | (k < digits[i]), c | (k != 0), m, d, digits, dp);
        }
        return dp[i][t][c] = ans;
    }
  public:
    int countWithout(int &n, int &d) {
        // code here
        vector<int> digits;
        for(int i = n; i > 0; i /= 10) digits.push_back(i % 10);
        vector<vector<vector<int>>> dp(digits.size(), vector<vector<int>>(2, vector<int>(2, -1)));
        reverse(digits.begin(), digits.end());
        int ans = f(0, 0, 0, digits.size(), d, digits, dp);
        return ans;
    }
};
