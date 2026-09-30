class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int x = (-1) * (nums[i] + nums[j]);
                int l = j + 1, h = nums.size() - 1;
                int ind = -1;
                while (l <= h) {
                    int mid = (l + h) >> 1;
                    if (nums[mid] == x) {
                        ind = mid;

                        break;
                    } else if (nums[mid] > x) {
                        h = mid - 1;
                    } else
                        l = mid + 1;
                }
                if (ind != -1) {
                    vector<int> temp = {nums[i], nums[j], nums[ind]};
                    // nums[i]=INT_MAX,nums[j]=INT_MAX,nums[ind]=INT_MAX;
                    sort(temp.begin(), temp.end());
                    ans.insert(temp);
                }
            }
        }

        vector<vector<int>>ans1;
        for(auto it:ans)ans1.push_back(it);
        return ans1;
    }
};