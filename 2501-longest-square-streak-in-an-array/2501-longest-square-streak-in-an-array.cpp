class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<long long> numSet(nums.begin(), nums.end());
        int maxCount = -1;
        for (int num : nums) {
            long long current = num;
            int count = 1;

            while (numSet.count(current * current)) {
                current *= current;
                count++;
            }
            if (count > 1) {
                maxCount = max(maxCount, count);
            }
        }
        return maxCount;
    }
};
