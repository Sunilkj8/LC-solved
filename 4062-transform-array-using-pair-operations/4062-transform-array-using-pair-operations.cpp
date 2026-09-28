class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long s_sum=accumulate(source.begin(),source.end(),0LL);
        long long t_sum=accumulate(target.begin(),target.end(),0LL);

        return s_sum==t_sum;
    }

};