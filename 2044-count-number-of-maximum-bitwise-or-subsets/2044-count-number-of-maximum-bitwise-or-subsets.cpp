class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int max_or = 0, count = 0;
        for (int num : nums) {
            max_or |= num;
        }
        int total_subsets = 1 << n;  
        for (int mask = 0; mask < total_subsets; ++mask) {
            int curr_or = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {  
                    curr_or |= nums[i];
                }
            }
            if (curr_or == max_or) {
                ++count;
            }
        }
        return count;
    }
};