class Solution {
public:
    int expandAroundCenter(int l, int r, string s) {
        int cnt = 0;
        while (l >= 0 && r < s.size()) {
            if (s[l] == s[r]) {
                cnt++;
                l--, r++;
            } else
                break;
        }

        return cnt;
    }
    int countSubstrings(string s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            int even = expandAroundCenter(i, i + 1, s);
            int odd = expandAroundCenter(i, i, s);
            cnt += even;
            cnt += odd;
        }

        return cnt;
    }
};