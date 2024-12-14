class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long result = 0;
        int n = nums.size();
        multiset<int> window; 
        int left = 0;
        for (int right = 0; right < n; ++right) {

            window.insert(nums[right]);

            while (*window.rbegin() - *window.begin() > 2) {
                window.erase(window.find(nums[left]));
                left++;
            }
            result += (right - left + 1);
        }

        return result;
    }
};