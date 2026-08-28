class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr,
               map<int, bool> &mpp) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (mpp[nums[i]]!=1) {
                curr.push_back(nums[i]);
                mpp[nums[i]] = 1;
            solve(nums, ans, curr, mpp);
            mpp[nums[i]]=0;
            curr.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        map<int,bool>mpp;
        solve(nums,ans,curr,mpp);
        return ans;
    }
};