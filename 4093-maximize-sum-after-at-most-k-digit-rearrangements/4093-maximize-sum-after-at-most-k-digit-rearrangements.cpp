class Solution {
public:
    int maxN(int num) {
        string s = to_string(num);
        sort(s.begin(),s.end());
        reverse(s.begin(), s.end());
        int n = stoi(s);
        if (num > n)
            return num;
        return n;
    }

    long long maximizeSum(vector<int>& nums, int k) {
         
         
       long long sum=0;
       vector<long long>temp;
       for(int i=0;i<nums.size();i++){
         temp.push_back(maxN(nums[i])-nums[i]);
         sum+=nums[i];
       }

       sort(temp.begin(),temp.end(),greater<int>());
       for(int i=0;i<temp.size() && k--;i++){
          sum+=temp[i];
       }

       return sum;
    }
};