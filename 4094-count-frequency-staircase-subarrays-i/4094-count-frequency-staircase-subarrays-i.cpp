class Solution {
public:
   bool isValid(vector<int>&a,map<int,int>&mpp){
       for(int i=0;i<a.size();i++){
          if(mpp[a[i]]!=i+1)return 0;
       }
       return 1;
   }
    int countStaircase(vector<int>& nums) {
        
  int cnt=0;
        for(int i=0;i<nums.size();i++){
            vector<int>temp;
            map<int,int>mpp;
            for(int j=i;j<nums.size();j++){
              if(mpp[nums[j]]<=0){
                temp.push_back(nums[j]);
              }
              mpp[nums[j]]++;
              if(isValid(temp,mpp))cnt++;
            }
        }

        return cnt;
    }
};