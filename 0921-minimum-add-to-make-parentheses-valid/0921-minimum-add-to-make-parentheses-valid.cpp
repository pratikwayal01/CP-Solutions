class Solution {
public:
    int minAddToMakeValid(string s) {
        int count1=0,count2=0;
        for(auto i:s){
            if(i=='('){
                ++count1;
            }
            else if(i==')' && count1>0){
                --count1;
            }
            else{
                ++count2;
            }
        }
        return count1+count2;
    }
};