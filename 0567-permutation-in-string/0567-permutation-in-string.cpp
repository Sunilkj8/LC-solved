class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // iterate over s2 and stop when you encounter an character of s1
        map<char,int>mpp;
        map<char,int>temp;
        for(char ch:s1)mpp[ch]++;
        temp=mpp;

        for(int i=0;i<s2.size();i++){
            if(s2.size()-i+1<s1.size())return 0;
            if(mpp.find(s2[i])!=mpp.end()){
                int r=i;
                while(r<s2.size()){
                    if(mpp.find(s2[r])!=mpp.end()){
                        mpp[s2[r]]--;
                        if(mpp[s2[r]]<=0)mpp.erase(s2[r]);
                        r++;
                    }
                    else{
                        break;
                    }
                }
                
                if(mpp.size()==0)return 1;
                 mpp=temp;
            }
        }

        return 0;
    }
};