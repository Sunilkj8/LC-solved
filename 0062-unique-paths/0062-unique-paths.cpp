class Solution {
public:
    int m, n;
    int uniquePaths(int r, int c) {
        m = r, n = c;
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[m - 1][n - 1] = 1;
        for (int i = m - 1; i >= 0; i--) {
            int j = n - 1;
            if (i == m - 1) {
                j = n - 2;
            }
            for (; j >= 0; j--) {
                int right, down;
                if (j + 1 >= n)
                    right = 0;
                else
                    right = dp[i][j + 1];
                if (i + 1 >= m)
                    down = 0;
                else
                    down = dp[i + 1][j];

                dp[i][j] = right + down;
            }
        }

        return dp[0][0];
    }
};