class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            for(int j=1;j<nums.size();j++){
                if(i<j && nums[i] + nums[j] < target){
                    count++;
                }
            }
        }
        return count;
    }
};