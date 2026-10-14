class Solution {
public:
    void genBinStr(int n, string curr, vector<string> &ans, int k)
{
    if (curr.size() > 1 && curr[curr.size() - 1] == curr[curr.size() - 2] && curr[curr.size() - 1] == '1' && curr[curr.size() - 2] == '1')
        return;
    if (curr.size() == n)
    {
        int cost = 0;
        for (int i = 0; i < n; i++)
        {
            if (curr[i] == '1')
                cost += i;
        }
        if (cost > k)
            return;
        ans.push_back(curr);
        return;
    }

    genBinStr(n, curr + '0', ans, k);

    genBinStr(n, curr + '1', ans, k);
}
    vector<string> generateValidStrings(int n, int k) {

     vector<string>ans;
     genBinStr(n,"",ans,k);
      

     return ans;


    }
};