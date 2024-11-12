class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items,vector<int>& queries) {
        sort(items.begin(), items.end());
        int m = queries.size();
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < m; ++i) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());
        vector<int> answer(m, 0);
        int maxBeauty = 0;
        int j = 0;
        for (const auto& [priceLimit, originalIndex] : sortedQueries) {
            while (j < items.size() && items[j][0] <= priceLimit) {
                maxBeauty = max(maxBeauty, items[j][1]);
                ++j;
            }

            answer[originalIndex] = maxBeauty;
        }

        return answer;
    }
};