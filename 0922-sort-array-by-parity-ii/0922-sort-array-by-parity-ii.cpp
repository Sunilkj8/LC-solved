class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int>ans(nums.size());
         vector<int>even;
         vector<int>odd;
         int evenCt=0;
         int oddCt=0;
        for(int i=0;i<nums.size();i++){
          if(nums[i]%2==0){
             even.push_back(nums[i]);
          }
          else odd.push_back(nums[i]);
        }
        for(int i=0;i<ans.size();i++){
            if(i%2==0){
               ans[i]=even[evenCt];
               evenCt++;
            }
            else{
                 ans[i]=odd[oddCt];
               oddCt++;
            }
        }

        return ans;
    }
};