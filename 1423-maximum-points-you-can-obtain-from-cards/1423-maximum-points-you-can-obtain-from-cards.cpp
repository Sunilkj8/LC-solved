class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        if(cardPoints.size()==k)return accumulate(cardPoints.begin(),cardPoints.end(),0);
        int score = 0;
        int i = 0;
        int maximum_score=INT_MIN;
        for (; i < k; i++) {
            score += cardPoints[i];
        }
       i--;
       maximum_score=score;
        for (int j = cardPoints.size() - 1; j >= cardPoints.size()-k; j--) {
            score-=cardPoints[i--];
            score+=cardPoints[j];
            maximum_score=max(maximum_score,score);
        }

        return maximum_score;
    }
};