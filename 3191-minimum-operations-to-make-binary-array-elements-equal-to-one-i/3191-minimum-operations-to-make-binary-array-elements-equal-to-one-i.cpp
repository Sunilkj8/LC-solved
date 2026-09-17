class Solution {
public:
    int minOperations(vector<int>& nums) {
        int l = 0;
        int cnt = 0;
        while (l < nums.size()) {
             if(nums[l]==0){
                int r=l;
                if(l+3<=nums.size()){
                    while(r<l+3){
                        nums[r]=!nums[r];
                        r++;
                    }
                    cnt++;
                }
             }
             l++;
        }
      for(int i=0;i<nums.size();i++){
        if(nums[i]!=1)return -1;
      }
        return cnt;
    }
};