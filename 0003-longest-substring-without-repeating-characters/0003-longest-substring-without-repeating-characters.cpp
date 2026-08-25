class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int,int>mpp;
        int maxLen=0;
        int l=0,r=0;
        while(r<s.size()){
            if(mpp.find(s[r])!=mpp.end()){
                if(l<=mpp[s[r]])
                l=mpp[s[r]]+1;
            }
          maxLen=max(maxLen,r-l+1);
          mpp[s[r]]=r;
            r++;
        }
        return maxLen;
    }
};