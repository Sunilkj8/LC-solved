class Solution {
public:
    
    map<int,double>mpp;
    double custom_pow(double x, long long n) {
        if(n==0)return 1;
        if (n == 1)
            return x;
        if(mpp.find(n)!=mpp.end())return mpp[n];
        double left, right;
        if (n % 2 != 0) {
            left=custom_pow(x,n-1);
            right=custom_pow(x,1);

        } else {
            left=custom_pow(x,n/2);
            right=custom_pow(x,n/2);
        }

        return mpp[n]=left * right;
    }

    double myPow(double x, int n) {
        double ans;
        // for negative n
       long long nn=n;
       if(nn<0)nn=-1*nn;

        if (n < 0) {
            ans = 1 / custom_pow(x, nn);
            return ans;
        }

        // for positive n
        ans = custom_pow(x, nn);

        return ans;
    }
};