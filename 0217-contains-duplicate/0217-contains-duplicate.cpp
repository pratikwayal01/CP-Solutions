class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int x:nums){
            mpp[x]++;
            if(mpp[x]>=2){
                return true;
            }
        }
        return false;
    }
};