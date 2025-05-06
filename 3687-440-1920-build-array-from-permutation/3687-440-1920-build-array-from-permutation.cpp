class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int>arr(nums.size());
        for(int i=0;i<nums.size();i++){
            arr[i]=nums[nums[i]];
        }
        return arr;
    }
};