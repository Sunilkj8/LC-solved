class Solution {
public:
    int minLights(vector<int>& lights) {
        int maxRight = INT_MIN;
        int minLeft = INT_MAX;
        int n = lights.size();

        // illumination array to check which portions of the road are
        // illuminated
        vector<int> temp(n, 0);

        for (int i = 0; i < n; i++) {
            if (lights[i] > 0) {
                maxRight = max(maxRight, min(n - 1, i + lights[i]));
            }
            if (i <= maxRight)
                temp[i] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (lights[i] > 0) {
                minLeft = min(minLeft, max(0, i - lights[i]));
            }
            if (i >= minLeft)
                temp[i] = 1;
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if ((i + 1 >= n || temp[i + 1] == 1) && temp[i] == 0) {
                cnt++;
                temp[i] = 1;
                if (i - 1 >= 0)
                    temp[i - 1] = 1;
            } else if (temp[i] == 0) {
                if (i - 1 >= 0 && i + 1 < n && temp[i - 1] == 0 &&
                    temp[i + 1] == 0) {

                    cnt++;
                    temp[i] = 1;
                    temp[i + 1] = 1;
                    temp[i - 1] = 1;
                }
            }
        }

        return cnt;
    }
};