class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) { 
        map<int, int> mpp;
        for(int i:nums){
            mpp[i]++;
        }
        for(int i=k;i<=1000;i+=k){
            if(mpp.find(i)==mpp.end()){
             return i;
            }
        }
        return -1;
    
       
    
     }
};