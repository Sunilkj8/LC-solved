class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = INT_MIN;
        int ar;
        int n = height.size();
        int l = 0, r = n - 1;
        while (l < r) {

            ar = min(height[l], height[r]) * (r - l);

            maxA = max(maxA, ar);
            if(height[l]<height[r])l++;
            else r--;
        }

        return maxA;
    }
};