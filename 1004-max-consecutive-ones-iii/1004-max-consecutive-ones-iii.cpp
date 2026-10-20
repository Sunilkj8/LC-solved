class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
         int l=0,r=0;
         map<int,int>mpp;
         int len=0;
         while(r<nums.size()){
            mpp[nums[r]]++;
            while(l<nums.size() && mpp[0]>k){
               mpp[nums[l]]--;
               if(mpp[nums[l]]==0)mpp.erase(nums[l]);
               l++;
            }
            len=max(len,r-l+1);
            r++;
         }

         return len;
    }
};