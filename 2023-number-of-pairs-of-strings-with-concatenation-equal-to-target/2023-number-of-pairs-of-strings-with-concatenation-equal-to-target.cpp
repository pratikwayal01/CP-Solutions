class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i != j && (nums[i] + nums[j]) == target) {
                    count++;
                }
            }
        }
        return count;
    }
};