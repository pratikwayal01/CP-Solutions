class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
     int n = nums.size();
    vector<int> invalid(n, 0);
    vector<int> prefixInvalid(n + 1, 0);

    for (int i = 0; i < n - 1; ++i) {
        invalid[i] = (nums[i] % 2 == nums[i + 1] % 2);
        prefixInvalid[i + 1] = prefixInvalid[i] + invalid[i];
    }
    prefixInvalid[n] = prefixInvalid[n - 1];

    vector<bool> result;
    for (auto& query : queries) {
        int from = query[0], to = query[1];
        result.push_back(prefixInvalid[to] - prefixInvalid[from] == 0);
    }

    return result;
    }
};