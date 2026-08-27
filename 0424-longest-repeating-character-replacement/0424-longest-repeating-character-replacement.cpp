class Solution {
public:
    int characterReplacement(string s, int k) {

        int l=0, r = 0;
        int maxLen = 0;
        int maxFreq = 0;
        vector<int> hash(26, 0);
        while (r < s.size()) {
            hash[s[r] - 'A']++;
            maxFreq = max(maxFreq, hash[s[r] - 'A']);
            int changes = ((r - l) + 1) - maxFreq;
            if (changes <= k)
                maxLen = max(maxLen, (r - l) + 1);
            else {
                hash[s[l]-'A']--;
                l++;
            }
            r++;
        }
        return maxLen;
    }
};