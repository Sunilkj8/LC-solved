class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int i = 0;
        int j = n - 1;
        int score = 0;
        int maximum_score=INT_MIN;
        while (i < k) {
            score += cardPoints[i];
            maximum_score=max(maximum_score,score);
            i++;
        }

        i--;
        while (j >= n - k) {
            score -= cardPoints[i];
            i--;
            score += cardPoints[j];
            maximum_score=max(maximum_score,score);
            j--;
        }

        return maximum_score;
    }
};