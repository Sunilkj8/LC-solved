class Solution {
public:
    int m, n;
    int fn(int i, int j, vector<vector<int>>& dp) {
        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        if (i >= m || j >= n)
            return 0;
        if (dp[i][j] != -1) {

            return dp[i][j];
        }
        int right = fn(i, j + 1, dp);
        int down = fn(i + 1, j, dp);
        dp[i][j] = right + down;
        return right + down;
    }

    int uniquePaths(int r, int c) {
        m = r, n = c;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = fn(0, 0, dp);

        return ans;
    }
};