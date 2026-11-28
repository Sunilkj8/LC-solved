class Solution {
public:
    int finalElement(vector<int>& nums) {
        int m=nums.size();
        if(m==1)return nums[0];

        return max(nums[0],nums[m-1]);

        
        
    }
};