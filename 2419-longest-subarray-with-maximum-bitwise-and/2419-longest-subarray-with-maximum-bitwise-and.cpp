class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        int count = 0;
        int len = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] == mx) {
                count++;
                len = max(len, count);
            } else {
                count = 0;
            }
        }
        return len;
    }
};