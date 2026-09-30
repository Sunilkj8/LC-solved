class Solution {
public:
    int n, m;
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int j = 0; j < m; j++) {
            dp[n - 1][j] = matrix[n - 1][j];
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                int dLeft;
                int down = dp[i + 1][j];
                int dRight;
                if (j - 1 < 0)
                    dLeft = INT_MAX;
                else {
                    dLeft = dp[i + 1][j - 1];
                }
                if (j + 1 >= m)
                    dRight = INT_MAX;
                else {
                    dRight = dp[i + 1][j + 1];
                }

                dp[i][j] = matrix[i][j] + min(dLeft, min(dRight, down));
            }
        }

        return *min_element(dp[0].begin(), dp[0].end());
    }
};