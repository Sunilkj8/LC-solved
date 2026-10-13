class Solution {
public:
    bool solve(vector<int>&nums,int idx,int k,vector<vector<int>>&dp){
        if(k==0)return 1;
        if(idx==0 && nums[idx]==k)return 1;
        if(idx==0 && nums[idx]!=k)return 0;
        if(dp[idx][k]!=-1)return dp[idx][k];
        bool notTake=solve(nums,idx-1,k,dp);
        bool take=false;
        if(k-nums[idx]>=0){
            take=solve(nums,idx-1,k-nums[idx],dp);
        }

        return dp[idx][k]=take|notTake;
    }
    bool canPartition(vector<int>& nums) {
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        
        if(totalSum%2!=0)return 0;
        int k=totalSum/2;
        vector<vector<int>>dp(nums.size(),vector<int>(k+1,-1));

return solve(nums,nums.size()-1,k,dp);

    }
};