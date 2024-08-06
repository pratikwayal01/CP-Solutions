class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> mpp;
        for (char ch : word) {
            mpp[ch]++;
        }

        vector<int> arr;
        for (const auto& pair : mpp) {
            arr.push_back(pair.second);
        }

        sort(arr.rbegin(), arr.rend());

        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            count += arr[i] * (i / 8 + 1); 
        }

        return count;
    }
};