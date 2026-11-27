class Solution {
public:
     
    int minGroups(vector<vector<int>>& a) {
         
        vector<int> f;
        vector<int> s;

        for (int i = 0; i < a.size(); i++) {
            f.push_back(a[i][0]);
            s.push_back(a[i][1]);
        }
        sort(f.begin(),f.end());
        sort(s.begin(),s.end());
        int mCnt = 1;
        int i=1,j=0;
        int cnt=1;
        while(i<f.size() && j<s.size()){
          if(f[i]<=s[j]){
            cnt++;
            mCnt=max(mCnt,cnt);
          }
          else{
            j++;
          }
            i++;
        }
        return mCnt;
         


      
    }
};