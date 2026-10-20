class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, r = 0;
        map<int, int> mpp;
        int cnt = 0;
        int maxSm = INT_MIN;

        while (r < fruits.size()) {
            cnt++;
            mpp[fruits[r]]++;
            while (l < fruits.size() && mpp.size() > 2) {
                cnt--;
                mpp[fruits[l]]--;
                if (mpp[fruits[l]] == 0)
                    mpp.erase(fruits[l]);
                l++;
            }
            maxSm=max(maxSm,cnt);
            r++;
        }
        return maxSm;
    }
};