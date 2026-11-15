class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int MOD=1e9+7;
        long long  cnt=0;
        vector<int>parityA;
        int sum=0;
        for(int i=0;i<arr.size();i++){
          sum+=arr[i];
          if(sum%2==0)parityA.push_back(0);
          else parityA.push_back(1);
        }
        
         int e=1;
         int o=0;

         for(int i=0;i<parityA.size();i++){
            if(parityA[i]==0){
                e++;
                cnt+=o % MOD;
            }
            else{
                o++;
                cnt+=e % MOD;
            }
         }

        return cnt % MOD;
    }
};