class Solution {
public:
    int solve(int idx, vector<int>& nums,vector<int>&dp) {
        if (idx >= nums.size()) {
            return 0;
        }
        if(dp[idx]!=-1)return dp[idx];
        int jump1 = solve(idx + 2, nums,dp);
        int jump2 = solve(idx + 3, nums,dp);
        return dp[idx]=nums[idx] + max(jump1, jump2);
    }

    int rob(vector<int>& nums) {
        int maxAmt = INT_MIN;
        vector<int> dp(nums.size(), -1);
        for (int i = 0; i < nums.size(); i++) {

            maxAmt = max(maxAmt, solve(i, nums,dp));
        }
        return maxAmt;
    }
};