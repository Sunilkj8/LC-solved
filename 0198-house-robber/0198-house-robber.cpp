class Solution {
public:
   int solve(vector<int>&nums,int idx,vector<int>&dp){
       if(idx>=nums.size())return 0;
       if(dp[idx]!=-1)return dp[idx];
       return dp[idx]= nums[idx]+max(solve(nums,idx+2,dp),solve(nums,idx+3,dp));
   }
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        if(nums.size()==2)return max(nums[0],nums[1]);
        vector<int>dp(nums.size()+1,-1);
        int first=nums[0]+max(solve(nums,2,dp),solve(nums,3,dp));
        int second=nums[1]+max(solve(nums,3,dp),solve(nums,4,dp));
        return max(first,second);
    }
};