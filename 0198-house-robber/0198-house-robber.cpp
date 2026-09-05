class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        vector<int> dp(n);
        dp[n - 1] = nums[n - 1];
        dp[n - 2] = nums[n - 2];
        for (int i = n - 3; i >= 0; i--) {
            if (i + 3 >= n)
                dp[i] = nums[i] + dp[i + 2];
            else if (dp[i + 2] > dp[i + 3]) {

                dp[i] = nums[i] + dp[i + 2];
            } else {
                dp[i] = nums[i] + dp[i + 3];
            }
        }

        return max(dp[0], dp[1]);
    }
};