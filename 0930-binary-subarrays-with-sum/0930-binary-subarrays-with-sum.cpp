class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int>mpp;
        mpp[0]=1;
        int cnt=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
           sum+=nums[i];
           if(mpp.find(sum-goal)!=mpp.end()){
              cnt+=mpp[sum-goal];
           }
           mpp[sum]++;
        }

        return cnt;
    }
};