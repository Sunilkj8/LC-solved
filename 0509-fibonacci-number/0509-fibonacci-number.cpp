class Solution {
public:
    int fib(int n) {
        int a=0;
        int b=1;
        if(n==0) return 0;
        if(n==1 || n==2)return 1;
        int nthTerm;
        for(int i=2;i<=n;i++){
          nthTerm=a+b;
          a=b;
          b=nthTerm;
        }
        return nthTerm;
    }
};