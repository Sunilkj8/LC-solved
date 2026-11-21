class Solution {
public:
   static bool customComp(vector<int>& a, vector<int>& b) {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> temp;
        sort(intervals.begin(), intervals.end(), customComp);
        temp.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= temp.back()[1])
                temp.push_back(intervals[i]);
        }

        return intervals.size() - temp.size();
    }
};