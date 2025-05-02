class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        unordered_map<int, int> prefixCount;
        int sum = 0;
        int count = 0;
        prefixCount[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (prefixCount.find(sum - k) != prefixCount.end()) {
                count += prefixCount[sum - k];
            }
            prefixCount[sum]++;
        }
        return count;
    }
};