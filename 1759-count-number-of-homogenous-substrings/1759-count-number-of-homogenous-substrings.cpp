class Solution {
public:
    int countHomogenous(string s) {
        long long  cnt = 0;
        int i = 0, j = 0;
        int mod = 1e9 + 7;
        map<char, int> mpp;
        while (j < s.size()) {
            
            mpp[s[j]]++;
             while(mpp.size()>1){
                
                mpp[s[i]]--;
                if(mpp[s[i]]==0)mpp.erase(s[i]);
                i++;
                
             }
            cnt+=mpp[s[j]]  ;
             j++;
        }

        return cnt %mod ;
    }
};