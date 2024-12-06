class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> mpp(banned.begin(), banned.end());
        int sum = 0;
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (mpp.find(i) == mpp.end() && sum + i <= maxSum) {
                sum += i;
                count++;
            }
        }
        return count;
    }
};