class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size();
        bool allSame = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[0]) {
                allSame = 0;
                break;
            }
        }

        if (allSame)
            return 0;

        int i = 0, r = 0;
        long long minC = LLONG_MAX;
        while (i < n - 1) {
            while (r < n && nums[r] == nums[i])
                r++;
            if (r > 1) {

                long long cost = (n - (r-i)) * static_cast<long long>(nums[i]);
                minC = min(minC, cost);
            }
            i = r;
        }

        return minC;
    }
};