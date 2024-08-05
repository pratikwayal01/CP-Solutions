class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (auto x : nums) {
            mpp[x]++;
        }
        int maxFrequency = 0;
        int count = 0;

        for (const auto& pair : mpp) {
            if (pair.second > maxFrequency) {
                maxFrequency = pair.second;
                count = pair.second;
            } else if (pair.second == maxFrequency) {
                count += pair.second; ;
            }
        }

        return count;
    }
};