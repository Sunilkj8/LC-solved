class Solution {
public:
   inline static vector<long long> e, o;
    inline static bool flag=0;
    void generatePalindromes() {
        if(flag)return;
        for (long long i = 1; i <= 1e5; i++) {
            string s = to_string(i);
            string r = s;
            reverse(r.begin(), r.end());
            long long a = stoll(s + r);
            long long b = stoll(s + r.substr(1, r.size() - 1));

            if (i < 1e9 && a % 2 == 0) {
                e.push_back(a);
                e.push_back(b);
            }
            if (i < 1e9 && a % 2 != 0) {
                o.push_back(a);
                o.push_back(b);
            }
        }
        flag=1;
        sort(e.begin(), e.end());
        sort(o.begin(), o.end());
    }
    long long minOperations(vector<int>& nums) {
         
        generatePalindromes();

        long long minOps = 0;
        for (long long i = 0; i < nums.size(); i++) {
            long long ind;
            bool even=0;
            if (nums[i] % 2 == 0) {
                even=1;
                ind = lower_bound(e.begin(), e.end(), nums[i]) - e.begin();
                if(ind-1<0)minOps+=abs(nums[i]-e[ind])/2;
                else{
                    minOps+=min(abs(nums[i]-e[ind-1])/2,abs(nums[i]-e[ind])/2);
                }
            } else {
                even=0;
                ind = lower_bound(o.begin(), o.end(), nums[i]) - o.begin();

                 if(ind-1<0)minOps+=abs(nums[i]-o[ind])/2;
                else{
                    minOps+=min(abs(nums[i]-o[ind-1])/2,abs(nums[i]-o[ind])/2);
                }
            }
            
        }

        return minOps;
    }
};