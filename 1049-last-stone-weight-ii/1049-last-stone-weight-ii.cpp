class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int totalSum = accumulate(stones.begin(), stones.end(), 0);
        vector<vector<bool>> dp(n, vector<bool>(totalSum + 1, 0));
        for (int i = 0; i < n; i++)
            dp[i][0] = 1;
        dp[0][stones[0]] = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= totalSum; j++) {
                bool notTake = dp[i - 1][j];
                bool take = 0;
                if (stones[i] <= j) {
                    take = dp[i - 1][j - stones[i]];
                }
                dp[i][j] = take | notTake;
            }
        }
        int minDiff=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<=totalSum;j++){
                int s1,s2;
                if(dp[i][j]){
                  s1=j;
                  s2=abs(j-totalSum);
                }
                minDiff=min(minDiff,abs(s1-s2));
            }
        }
        return minDiff;
    }
};