class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int count = 0;
        for (int num : nums) {
            int key = k - num;
            if (mpp[key] > 0) {
                count++;
                mpp[key]--;
            } else {
                mpp[num]++;
            }
        }

        return count;
    }
};