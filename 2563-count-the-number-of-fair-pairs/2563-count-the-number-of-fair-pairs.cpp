class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long count = 0;
        for (int i = 0; i < n; ++i) {
            int lo = lower - nums[i], hi = upper - nums[i];
            int left = lower_bound(nums.begin() + i + 1, nums.end(), lo) - nums.begin();
            int right = upper_bound(nums.begin() + i + 1, nums.end(), hi) - nums.begin();
            count += (right - left);
        }
        return count;
    }
};