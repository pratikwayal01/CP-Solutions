class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int num=0;
        map<int,int>mpp;
        for(auto x:nums){
            mpp[x]++;
        }
        for(auto pair:mpp){
            if(pair.second>=2){
                num=pair.first;
            }
        }
        return num;
    }
};