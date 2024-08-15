class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;
        for(auto x:bills){
            if(x==5){
                ++five;
            }
            else if(x==10){
                --five;
                ++ten;
            }
            else {
                if(ten>0){
                    --ten;
                    --five;
                }
                else {
                    five-=3;
                } 
            }
              if(five<0){
                    return false;
                }

        }
        return true;
    }
};