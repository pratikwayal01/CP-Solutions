class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        vector<int> result;
        for (int num : nums) {
            int index = lower_bound(arr.begin(), arr.end(), num) - arr.begin();
            result.push_back(index);
        }

        return result;
    }
};