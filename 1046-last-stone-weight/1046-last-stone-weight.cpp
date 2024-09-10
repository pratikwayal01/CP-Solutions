class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() > 1) {
            int temp = pq.top();
            pq.pop();
            int temp1 = pq.top();
            pq.pop();
            int diff = temp - temp1;
            if (diff != 0) {
                pq.push(diff);
            } else {
                pq.push(0);
            }
        }
        int ans = pq.top();
        return ans;
    }
};