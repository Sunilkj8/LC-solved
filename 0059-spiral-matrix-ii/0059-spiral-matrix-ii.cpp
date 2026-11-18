class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int elem = 1;
        for (int i = 0; i < (n + 1) / 2; i++) {
            // l -> r
            for (int j = i; j <= n - i - 1; j++) {
                ans[i][j] = elem++;
            }
            // u -> d

            for (int j = i + 1; j <= n - i - 1; j++) {
                ans[j][n - i - 1] = elem++;
            }
            // r -> l
            for (int j = n - i - 2; j >= i; j--) {
                ans[n - i - 1][j] = elem++;
            }
            // d -> u
            for (int j = n - i - 2; j > i; j--) {
                ans[j][i] = elem++;
            }
        }

        return ans;
    }
};