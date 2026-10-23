class Solution {
public:
    int n;
    int solve(vector<int>&nums,int idx,vector<int>&dp){
        if(idx==n-1)return 1;
        if(dp[idx]!=-1)return dp[idx];
        int minJump=INT_MAX;
        for(int j=1;j<=nums[idx];j++){
            int res;
            if(idx+j<n)
              res=solve(nums,idx+j,dp);
            if(res<INT_MAX)
            minJump=min(minJump,1+res);
        }
        // if(minJump==INT_MAX)return 0;
        return dp[idx]=minJump;
    }
    int jump(vector<int>& nums) {
       n=nums.size(); 
        if(n==1)return 0;

        vector<int>dp(n,-1);
        int minJump=INT_MAX;
        for(int j=1;j<=nums[0];j++){
            if(0+j<n)
            minJump=min(minJump,solve(nums,0+j,dp));
        }

    return minJump==INT_MAX?0:minJump;
    }
};