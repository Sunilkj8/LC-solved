class Solution {
    static const long long mod=1e9+7;
public:
    long long cust_pow(long long x, long long n) {
        
        long long ans = 1;
        while (n > 0) {
            if (n % 2 == 0) {
                x = (x * x) % mod;
            n = n / 2;
            } else {
                ans = (ans*x) % mod;
                n--;
            }
        }

        return ans;
    }
    int countGoodNumbers(long long n) {

        
        long long evenIndices = (n + 1) / 2;
        long long oddIndices = n / 2;
        long long evenWays = cust_pow(5, evenIndices) ;
        long long oddWays = cust_pow(4, oddIndices) ;

        return (evenWays * oddWays)%mod ;
    }
};