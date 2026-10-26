class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1)
            return n;
        int length = 0;
        int maxLen = INT_MIN;
        map<int, int> mpp;
        for (int i : nums)
            mpp[i]++;

        for (auto it : mpp) {
            if (mpp.find(it.first+1)!=mpp.end()) {
                length++;
                
            } else {
                maxLen = max(length, maxLen);
                length=0;
            }
        }

        return maxLen + 1;
    }
};