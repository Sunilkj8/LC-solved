class Solution {
public:

   int solve(vector<vector<int>>&triangle,int i,int j,vector<vector<int>>&dp){

   if(i>=triangle.size())return 0;
   if(dp[i][j]!=INT_MAX)return dp[i][j];
    int down=solve(triangle,i+1,j,dp);
    int dLeft=solve(triangle,i+1,j+1,dp);

    return dp[i][j]=triangle[i][j]+min(down,dLeft);
   }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();

        vector<vector<int>>dp(n);
        for(int i=0;i<n;i++){
            vector<int>temp(i+1,INT_MAX);
            dp[i]=temp;
        }
        return solve(triangle,0,0,dp);
    }
};