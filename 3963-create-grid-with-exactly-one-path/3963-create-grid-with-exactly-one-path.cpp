class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans(m);

        for(int i=0;i<m;i++){
            string s="";
            for(int j=0;j<n;j++){
                if(i==0){
                    s.push_back('.');
                }
                else{
                    if(j==n-1)s.push_back('.');
                    else s.push_back('#');
                }
            }
            ans[i]=s;
        }

        return ans;
    }
};