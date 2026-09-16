class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int sub_arr_smaller_equal_to_k = 0;
        int sub_arr_smaller_than_k = 0;

        int l = 0, r = 0;
        map<int, int> mpp;

        while (r < nums.size()) {
            mpp[nums[r]]++;
            if (mpp.size() > k) {
                while (mpp.size() > k) {
                    mpp[nums[l]]--;
                    if (mpp[nums[l]] == 0)
                        mpp.erase(nums[l]);
                    l++;
                }
            }
            sub_arr_smaller_equal_to_k += (r - l) + 1;

            r++;
        }
        l=0,r=0;
        mpp.clear();
        while (r < nums.size()) {
            mpp[nums[r]]++;
            if (mpp.size() >= k) {
                while (mpp.size() >= k) {
                    mpp[nums[l]]--;
                    if (mpp[nums[l]] == 0)
                        mpp.erase(nums[l]);
                    l++;
                }
            }
            sub_arr_smaller_than_k += (r - l) + 1;

            r++;
        }


        
        return (sub_arr_smaller_equal_to_k - sub_arr_smaller_than_k);
    }
};