class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fDeno=0;
        int tDeno=0;
         
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5)fDeno++;
            else if(bills[i]==10){
                if(fDeno>0){
                    fDeno--;
                    tDeno++;
                }
                else return 0;
            }
            else{
                if(fDeno>0 && tDeno>0){
                   fDeno--;
                   tDeno--;
                }
                else if(fDeno>=3){
                    fDeno-=3;
                }
                else return 0;
            }
        }

        return 1;
    }
};