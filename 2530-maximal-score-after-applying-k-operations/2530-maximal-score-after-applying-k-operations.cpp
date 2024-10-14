class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> pq;
        for (auto x : nums) {
            pq.push(x);
        }
        for (int i = 0; i < k; ++i) {
            int top = pq.top();
            pq.pop();
            ans += top;
            pq.push(ceil(top / 3.0));
        }

        return ans;
    }
};