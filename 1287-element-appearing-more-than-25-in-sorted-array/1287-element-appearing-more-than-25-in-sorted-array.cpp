class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mpp;
        for (int x : arr) {
            mpp[x]++;
        }
        for (const auto& pair : mpp) {
            if (pair.second > n / 4) {
                return pair.first;
            }
        }
        return -1;
    }
};