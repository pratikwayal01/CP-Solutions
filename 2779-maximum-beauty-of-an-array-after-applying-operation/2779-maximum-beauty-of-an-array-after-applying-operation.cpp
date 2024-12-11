class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

    int left = 0, max_beauty = 0;

 
    for (int right = 0; right < nums.size(); ++right) {
        while (nums[right] - nums[left] > 2 * k) {
            ++left;
        }
        max_beauty = max(max_beauty, right - left + 1);
    }

    return max_beauty;
    }
};