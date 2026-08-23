class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int basket1 = fruits[0];
        int basket2 = fruits[0];
        int l = 0, r = 0;
        int maxLen = 1;
        map<int, int> mpp;
        while (r < fruits.size()) {
            mpp[fruits[r]]++;
            while (mpp.size() > 2) {
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0)
                mpp.erase(fruits[l]);

                l++;
            }
            maxLen = max(maxLen, (r - l) + 1);
            r++;
        }
        return maxLen;
    }
};