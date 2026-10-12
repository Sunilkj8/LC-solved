class Solution {
public:
    bool isValid(long long num, int x) {
        string temp = to_string(num);
        int last = temp[temp.size() - 1] - '0';
        int first = temp[0] - '0';
       if(first==x && last==x)return 1;
        return 0;
    }
    int countValidSubarrays(vector<int>& nums, int x) {

        int l = 0, r = 0;
        int cnt = 0;
         
        for (int i = 0; i < nums.size(); i++) {
            long long sum = 0;
            for (int j = i; j <nums.size(); j++) {
                sum += nums[j];
                 if(sum % 10 == x && to_string(sum)[0] - '0' == x) {
                    cnt++;
                }
                
            }
        }
        return cnt;
    }
};