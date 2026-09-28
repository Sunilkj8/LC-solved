class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int maxPairs = 0;
        int cnt = 0;

        map<int, int> m;
        for (int i : nums) {
            m[i]++;
        }
        if (m.size() == 2)
            return nums.size() - 1;
        map<pair<int, int>, int> mpp;
        for (int i = 0; i < nums.size() - 1; i++) {
            int a = min(nums[i], nums[i + 1]);
            int b = max(nums[i], nums[i + 1]);
            if (a == b)
                cnt++;
            else
                mpp[{a, b}]++;
        }

        for (auto it : mpp) {
            maxPairs = max(maxPairs, it.second);
        }
        return cnt + maxPairs;
    }
};