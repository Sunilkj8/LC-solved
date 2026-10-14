class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int cnt=0;
        for(int x=1;x<=300;x++){
            
           if(abs(n-x)<=k && (n&x)==0)cnt+=x;
        }

        return cnt;
    }
};