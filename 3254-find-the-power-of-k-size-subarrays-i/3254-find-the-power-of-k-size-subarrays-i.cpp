class Solution {
public:
vector<int> resultsArray(vector<int>& nums, int k) {
    int consecutiveCount = 0;
    int maxElement = nums[0];
    vector<int> result;

    for (int i = 0; i < k - 1; i++) {
        if (nums[i] == nums[i + 1] - 1) {
            maxElement++;
        } else {
            consecutiveCount = i + 1;
            maxElement = nums[i + 1];
        }
    }

    if (consecutiveCount > 0) {
        result.push_back(-1);
    } else {
        result.push_back(maxElement);
    }

    for (int i = k; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1] + 1) {
            maxElement++;
            consecutiveCount--;
        } else {
            consecutiveCount = k - 1;
            maxElement = nums[i];
        }

        if (consecutiveCount > 0) {
            result.push_back(-1);
        } else {
            result.push_back(maxElement);
        }
    }

    return result;
}
};
