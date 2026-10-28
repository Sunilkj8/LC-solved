class Solution {
public:
    bool isValid(map<char,int>&mpp){
         int freq=0;
         for(auto it:mpp){
            if(freq==0)freq=it.second;
            else if(freq!=it.second)return 0;
         }
         return 1;
    }
    int longestBalanced(string s) {
        int maxLen=INT_MIN;
        for(int i=0;i<s.size();i++){
            map<char,int>mpp;
            
           for(int j=i;j<s.size();j++){
              mpp[s[j]]++;
              if(isValid(mpp)){
                  maxLen=max(maxLen,j-i+1);
              }
               
              
               
           }
        }

        return maxLen;
    }
};