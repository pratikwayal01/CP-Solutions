class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
         int n = nums.size();
    
    vector<int> left(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                left[i] = max(left[i], left[j] + 1);
            }
        }
    }


    vector<int> right(n, 1);
    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (nums[j] < nums[i]) {
                right[i] = max(right[i], right[j] + 1);
            }
        }
    }

    int maxMountainLength = 0;
    for (int i = 1; i < n - 1; i++) {
        if (left[i] > 1 && right[i] > 1) { 
            maxMountainLength = max(maxMountainLength, left[i] + right[i] - 1);
        }
    }
    return n - maxMountainLength;
    }
};