class Solution {
public:
    int rob(vector<int>& nums) {
          int prev1 = 0, prev2 = 0;

        for (int n : nums) {
            int temp = max(n + prev1, prev2);
            prev1 = prev2;
            prev2 = temp;
        }
        return prev2;
    }
};