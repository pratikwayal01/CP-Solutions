class Solution {
public:
    long long minimumSteps(string s) {
        long long count=0;
        int one=0;
        for(auto i:s){
            if(i=='1'){
                ++one;
            }
            else {
                count+=one;
            }
        }
        return count;
    }
};