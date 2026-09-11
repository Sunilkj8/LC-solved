class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char, int> mpp;
        mpp['a'] = -1;
        mpp['b'] = -1;
        mpp['c'] = -1;
        int substringCount = 0;
        int i = 0;
        while (i < s.size()) {
            mpp[s[i]]=i;
            if (mpp['a'] != -1 && mpp['b'] != -1 && mpp['c'] != -1) {
                int minimalKey = INT_MAX;
                minimalKey = min(minimalKey, mpp['a']);
                minimalKey = min(minimalKey, mpp['b']);
                minimalKey = min(minimalKey, mpp['c']);
                cout<<minimalKey<<endl;
                substringCount += minimalKey + 1;
            }
            i++;
        }

        return substringCount;
    }
};