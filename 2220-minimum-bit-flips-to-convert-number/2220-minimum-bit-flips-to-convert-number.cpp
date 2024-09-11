class Solution {
public:
    int minBitFlips(int start, int goal) {
       int ans = start ^ goal;
       int count=0;
       while(ans !=0){
        count +=ans & 1;
        ans>>=1;
       } 
       return count;
    }
};