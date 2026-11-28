class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> ans;
        ans.push_back(nums[0]);
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if(nums[i]==ans.back()){
                ans[ans.size()-1]+=nums[i];
                while(ans.size()>=2 && ans[ans.size()-1]==ans[ans.size()-2]){
                    ans[ans.size()-2]+=ans[ans.size()-1];
                    ans.pop_back();
                }
            }
            else{
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};