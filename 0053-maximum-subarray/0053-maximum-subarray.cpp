class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //Kadane Algorith
        int curr_sum = 0;
        int max_sum = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            curr_sum += nums[i];

            if (curr_sum > max_sum) {
                max_sum = curr_sum;
            }

            if (curr_sum < 0) {
                curr_sum = 0;
            }
        }

        return max_sum;
    }
};