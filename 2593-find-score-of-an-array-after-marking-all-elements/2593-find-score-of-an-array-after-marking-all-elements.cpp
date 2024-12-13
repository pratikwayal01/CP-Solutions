class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> marked(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>minHeap;

        for (int i = 0; i < n; ++i) {
            minHeap.emplace(nums[i], i);
        }
        long long score = 0;
        while (!minHeap.empty()) {
            auto [val, idx] = minHeap.top();
            minHeap.pop();
            if (marked[idx]) {
                continue;
            }
            score += val;
            marked[idx] = true;
            if (idx > 0) {
                marked[idx - 1] = true;
            }
            if (idx < n - 1) {
                marked[idx + 1] = true;
            }
        }

        return score;
    }
};