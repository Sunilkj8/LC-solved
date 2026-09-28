class Solution {
public:

  int fn(vector<vector<int>>&grid,int i,int j,int n,int m,vector<vector<int>>&dp){
     if(i>=n || j>=m)return 0;
     if(grid[i][j]==1)return 0;
     if(i==n-1 && j==m-1)return 1;
     if(dp[i][j]!=-1)return dp[i][j];
     int down=fn(grid,i+1,j,n,m,dp);
     int right=fn(grid,i,j+1,n,m,dp);
     return dp[i][j]=down+right;
  }



    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>>dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        return fn(obstacleGrid,0,0,obstacleGrid.size(),obstacleGrid[0].size(),dp);
    }
};