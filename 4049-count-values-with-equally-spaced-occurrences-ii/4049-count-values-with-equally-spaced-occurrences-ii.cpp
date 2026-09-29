class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int, vector<int>> mpp;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]].push_back(i);
        }

        // [1,8,1,5,1,5,8,5]
        // 1 -> {0,2,4}
        // 8 -> {1,6}
        // 5 -> {3,5,7}

        for (auto it : mpp) {
            if (it.second.size() >= 3) {
                bool isValid = false;
                int diff = abs(it.second[0] - it.second[1]);
                for (int i = 1; i < it.second.size() - 1; i++) {

                    if(abs(it.second[i]-it.second[i+1])==diff){
                        isValid=1;
                    }
                    else{
                        isValid=0;
                        break;
                    }
                }
                if(isValid)cnt++;
            }
        }

        return cnt;
    }
};