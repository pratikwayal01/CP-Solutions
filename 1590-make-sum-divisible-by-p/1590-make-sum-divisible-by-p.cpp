class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total_sum = accumulate(nums.begin(), nums.end(), 0LL);
        int rem = total_sum % p;
        if (rem == 0) {
            return 0;
        }
        unordered_map<int, int> prefix_map;
        prefix_map[0] = -1;
        long long prefix_sum = 0;
        int min_length = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum = (prefix_sum + nums[i]) % p;
            int target = (prefix_sum - rem + p) % p;
            if (prefix_map.find(target) != prefix_map.end()) {
                int subarray_length = i - prefix_map[target];
                min_length = std::min(min_length, subarray_length);
            }
            prefix_map[prefix_sum] = i;
        }
        return (min_length == nums.size()) ? -1 : min_length;
    }
};