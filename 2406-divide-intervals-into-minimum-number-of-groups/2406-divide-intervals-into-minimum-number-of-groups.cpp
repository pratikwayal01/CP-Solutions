class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        sort(intervals.begin(), intervals.end());
        int count = 0;  
        for (const auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            if (!pq.empty() && pq.top().first < start) {
                auto [time, num] = pq.top();
                pq.pop();
                pq.push({end, num});
            } else {
                pq.push({end, count});
                count++;
            }
        }
        
        return count;
    }
};