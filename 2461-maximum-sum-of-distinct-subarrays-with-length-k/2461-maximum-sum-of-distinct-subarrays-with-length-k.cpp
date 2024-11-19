class Solution {
public:
long long maximumSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    if (n < k) return 0; 

    long long current_sum = 0, max_sum = 0;
    unordered_map<int, int> mpp; 

    int start = 0; 
    for (int end = 0; end < n; end++) {
        current_sum += nums[end];
        mpp[nums[end]]++;


        while (end - start + 1 > k) {
            current_sum -= nums[start];
            mpp[nums[start]]--;
            if (mpp[nums[start]] == 0) {
                mpp.erase(nums[start]);
            }
            start++;
        }
    if (end - start + 1 == k && mpp.size() == k) {
            max_sum = max(max_sum, current_sum);
        }
    }

    return max_sum;
}

};