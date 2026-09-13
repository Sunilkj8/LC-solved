class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        long long ans = 0;
        while (s[i] == ' ')
            i++;
        bool isNegative = false;
        if (s[i] == '-') {
            isNegative = 1;
            i++;
        } else if (s[i] == '+')
            i++;
        while (i < s.length() && isdigit(s[i])) {
            if (isNegative && -(ans + (s[i] - '0')) < INT_MIN) {
                return INT_MIN;
            }
            if (!isNegative && ans + (s[i] - '0') > 2147483647) {
                return INT_MAX;
            }
            ans += s[i] - '0';
            ans *= 10;

            i++;
        }
        ans /= 10;
        if (isNegative)
            ans *= -1;
        return (int)ans;
    }
};