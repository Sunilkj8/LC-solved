class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int i = 0, j = 0;
        map<int, int> mpp;
        long long goodCnt = 0;
        while (j < nums.size()) {
            
            if(mpp[nums[j]]>0){
                k-=mpp[nums[j]];
            }
            mpp[nums[j]]++;
            
                while(k<=0){
                goodCnt+=nums.size()-j;
                    mpp[nums[i]]--;
                    k+=mpp[nums[i]];
                    i++;
                }
            
            j++;
        }

        return goodCnt;
    }
};