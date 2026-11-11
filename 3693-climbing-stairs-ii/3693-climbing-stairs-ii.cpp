class Solution {
public:
    int solve(vector<int>&a,int idx,int n,vector<int>&dp){
         if(idx==n){
            return a[idx];
         }
         if(dp[idx]!=-1)return dp[idx];
         int minVal=INT_MAX;
         for(int i=1;i<=3;i++){
            int j=idx+i;
            if(j<=n){
                int ans=solve(a,j,n,dp)+pow((j-idx),2);
                minVal=min(minVal,ans);
            }
         }
     return dp[idx]=a[idx]+minVal;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int>a={0};
        for(int i:costs)a.push_back(i);
        vector<int>dp(a.size()-1,-1);

         return solve(a,0,a.size()-1,dp);
    }
};