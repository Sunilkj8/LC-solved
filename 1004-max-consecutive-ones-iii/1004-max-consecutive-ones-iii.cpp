class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int zeroCnt = 0;
        int maxLen = 0;
        while (r < nums.size()) {
            if (nums[r] == 0) {
                zeroCnt++;
            }

            while (zeroCnt > k) {
                if (nums[l] == 0)
                    zeroCnt--;
                l++;
            }
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};