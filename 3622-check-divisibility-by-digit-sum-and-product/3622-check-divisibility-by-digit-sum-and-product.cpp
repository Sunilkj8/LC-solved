class Solution {
public:
    long long product(int n) {
        long long ans = 1;
        while (n != 0) {
            ans *= n % 10;
            n /= 10;
        }
        return ans;
    }
    long long sum(int n) {
        long long ans = 0;
        while (n != 0) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
    bool checkDivisibility(int n) {
        int sm=sum(n);
        int pd=product(n);
        // cout<<sm<<endl<<pd<<endl;
        return n%(sum(n)+ product(n))==0 ? 1 : 0;
    }
};