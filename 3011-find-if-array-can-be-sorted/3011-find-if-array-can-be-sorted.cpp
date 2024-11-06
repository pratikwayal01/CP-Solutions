class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        map<int, int> mpp;

    
        for (auto it : nums) {
            int cnt = 0;
            for (int i = 0; i < 31; i++) {
                if ((it & (1 << i))) {
                    cnt++;
                }
            }
            mpp[it] = cnt;
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] > nums[j]) {
                    if (mpp[nums[i]] != mpp[nums[j]]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};