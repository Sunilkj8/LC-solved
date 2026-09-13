class Solution {
public:
    string expandAroundCenter(int l, int r, string s) {
        while (l >= 0 && r < s.size()) {
            if (s[l] == s[r]) {
                l--, r++;
            } else
                break;
        }
        return s.substr(l + 1, r - l - 1);
    }
    string longestPalindrome(string s) {

        string longestPalin = s.substr(0, 1);
        for (int i = 0; i < s.size(); i++) {
            string odd = expandAroundCenter(i, i, s);
            string even = expandAroundCenter(i, i + 1, s);
            if (odd.size() > longestPalin.size()) {
                longestPalin = odd;
            }
            if (even.size() > longestPalin.size()) {
                longestPalin = even;
            }
        }

        return longestPalin;
    }
};