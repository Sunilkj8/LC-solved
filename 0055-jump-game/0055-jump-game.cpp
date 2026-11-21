class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxInd=nums[0];
        int n=nums.size();
        if(n==1)return 1;
        for(int i=1;i<n-1;i++){
             if(i>maxInd)return 0;
             maxInd=max(maxInd,i+nums[i]);
            
        }
      

      return maxInd>=n-1;

    }
};