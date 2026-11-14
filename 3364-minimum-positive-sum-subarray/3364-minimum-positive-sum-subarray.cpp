class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int minSum = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {

            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (j - i + 1 >= l && j - i + 1 <= r && sum>0) {
                    cout << sum << endl;
                   minSum= min(sum, minSum);
                }
            }
        }
        if (minSum == INT_MAX)
            return -1;
        return minSum;
    }
};