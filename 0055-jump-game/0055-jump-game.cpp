class Solution {
public:
   
   bool solve(vector<int>&nums,int idx,vector<int>&dp){
     if(idx>=nums.size()-1)return 1;
     bool canJ=false;

        if(dp[idx]!=-1)return dp[idx];
         
         for(int j=1;j<=nums[idx];j++){
            canJ=canJ|solve(nums,idx+j,dp);
         }
          
         
      

     return dp[idx]=canJ;

   }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool>dp(n,0);
        
        dp[n-1]=1;

        for(int i=n-2;i>=0;i--){
           for(int j=1;j<=nums[i];j++){
            if(i+j<=n-1)
              dp[i] =dp[i]|dp[i+j];
           }
        }
        return dp[0];
    }
};