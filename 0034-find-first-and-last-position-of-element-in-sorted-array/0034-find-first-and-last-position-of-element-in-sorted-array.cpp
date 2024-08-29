class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        map<int, vector<int>> mpp;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]].push_back(i);
        }
        if (mpp.find(target) != mpp.end()) {
            return {mpp[target].front(), mpp[target].back()};
        }
        return {-1, -1};
    }
};