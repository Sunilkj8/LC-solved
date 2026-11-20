class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> arr;
        arr.push_back(nums[0]);
        int lastCnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (arr.back() == nums[i]) {
                if (lastCnt <= 1) {
                    lastCnt++;
                    arr.push_back(nums[i]);
                }
            } else {
                arr.push_back(nums[i]);
                lastCnt = 1;
            }
        }

          nums=arr;
        return arr.size();
    }
};