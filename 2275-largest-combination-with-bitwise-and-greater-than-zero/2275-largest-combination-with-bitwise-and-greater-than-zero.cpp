class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxbit = 0;

        for (int bit = 0; bit < 32; ++bit) {
            int curr = 0;

            for (int num : candidates) {
                if (num & (1 << bit)) {
                    curr++;
                }
            }

            maxbit = max(maxbit, curr);
        }

        return maxbit;
    }
};