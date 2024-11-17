class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<long long, int>> dq;
        vector<long long> prefixSum(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        int minLength = INT_MAX;

        for (int i = 0; i <= n; i++) {
            while (!dq.empty() && prefixSum[i] - dq.front().first >= k) {
                minLength = min(minLength, i - dq.front().second);
                dq.pop_front();
            }

            while (!dq.empty() && dq.back().first >= prefixSum[i]) {
                dq.pop_back();
            }

            dq.emplace_back(prefixSum[i], i);
        }

        return (minLength == INT_MAX) ? -1 : minLength;
    }
};