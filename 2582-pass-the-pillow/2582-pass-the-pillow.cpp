class Solution {
public:
    int passThePillow(int n, int time) {
        int rem= time%(n-1);
        int pass=time/(n-1);
        if(pass&1){
            return n-rem;
         }else{
            return 1+rem;
         }
    }
};