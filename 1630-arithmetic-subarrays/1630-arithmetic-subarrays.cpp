class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    vector<bool> ans;
    for (int i = 0; i < l.size(); ++i) {
        vector<int> subarray(nums.begin() + l[i], nums.begin() + r[i] + 1);
        sort(subarray.begin(), subarray.end());
        bool isArithmetic = true;
        int difference = subarray[1] - subarray[0];
        for (int j = 1; j < subarray.size(); ++j) {
            if (subarray[j] - subarray[j - 1] != difference) {
                isArithmetic = false;
                break;
            }
        }
        ans.push_back(isArithmetic);
    }
    return ans;
    }
};