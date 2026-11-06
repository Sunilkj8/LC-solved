class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt = 0;

        for (int i = 0; i < arr1.size(); i++) {
            bool isVal = 0;
            for (int j = 0;  j < arr2.size(); j++) {
                int absVal = abs(arr1[i] - arr2[j]);
                if (absVal > d) {
                    isVal = 1;
                } else {
                    isVal = 0;
                    break;
                }
            }
            if (isVal)
                cnt++;
        }
        return cnt;
    }
};