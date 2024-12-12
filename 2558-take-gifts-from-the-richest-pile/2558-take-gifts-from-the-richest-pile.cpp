class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n=gifts.size();
        for(int i=1;i<=k;i++){
            sort(gifts.begin(),gifts.end());
            gifts[n-1]=(int)sqrt(gifts[n-1]);
        }
        long long sum=0;
        for(int i:gifts){
            sum+=i;
        }
        return sum;
    }
};