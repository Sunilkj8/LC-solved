class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;
        int sum = 0;
        int len = INT_MAX;

        while (r < nums.size()) {
            sum += nums[r];
            if (sum >= target) {
                len = min(len, r - l + 1);
            }
            if (sum > target) {
                while (sum > target) {
                    sum -= nums[l];
                    l++;
                    if(sum>=target)
                    len = min(len, r - l + 1);
                }
                
            }

            r++;
        }

        return len == INT_MAX ? 0 : len;
    }
};