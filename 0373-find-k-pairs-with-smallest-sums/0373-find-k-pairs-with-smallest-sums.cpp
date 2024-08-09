class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,int k) {
        priority_queue<pair<int, pair<int, int>>> Q;
        int m = nums1.size();
        int n = nums2.size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = nums1[i] + nums2[j];
                if (Q.size() < k) {
                    Q.push({sum, {nums1[i], nums2[j]}});
                } else if (Q.top().first > sum) {
                    Q.pop();
                    Q.push({sum, {nums1[i], nums2[j]}});
                } else {
                    break;
                }
            }
        }

        vector<vector<int>> ans;
        while (!Q.empty()) {
            auto temp = Q.top().second;
            ans.push_back({temp.first, temp.second});
            Q.pop();
        }

        return ans;
    }
};