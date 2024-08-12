class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int>mpp;
        int count=0;
        for(char& x:text){
            mpp[x]++;
        }
    int min_b = mpp['b'];
    int min_a = mpp['a'];
    int min_l = mpp['l'] / 2;
    int min_o = mpp['o'] / 2; 
    int min_n = mpp['n'];
    
    return min({min_b, min_a, min_l, min_o, min_n});
    }
};