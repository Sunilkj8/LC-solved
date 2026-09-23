class Solution {
public:
    int solve(int idx, vector<int>& nums, vector<int>& dp) {
        if (idx >=nums.size()) {
            return 0;
        }
        if (dp[idx] != -1)
            return dp[idx];

         int jump1=solve(idx+2,nums,dp);
         int jump2=solve(idx+3,nums,dp);
        return dp[idx] = nums[idx] + max(jump1, jump2);
    }

    int rob(vector<int>& nums) {
        int maxAmt1 = INT_MIN;
        int maxAmt2 = INT_MIN;
        if(nums.size()==1)return nums[0];
        vector<int>temp1,temp2;

        for(int i=0;i<nums.size();i++){
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=nums.size()-1)temp2.push_back(nums[i]);
        }
        vector<int> dp(temp1.size(), -1);
         
        for (int i = 0; i < temp1.size(); i++) {
            
            maxAmt1 = max(maxAmt1, solve(i, temp1, dp));
        }
        vector<int>dp2(temp2.size(),-1);
        for (int i = 0; i < temp2.size(); i++) {
            
            maxAmt2 = max(maxAmt2, solve(i, temp2, dp2));
        }
        
        return max(maxAmt1,maxAmt2);
    }
};