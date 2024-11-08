class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
     int maxVal = (1 << maximumBit) - 1;  
        int cumulativeXor = 0;
        vector<int> answer;
        
        for (int num : nums) {
            cumulativeXor ^= num;
        }
        
        
        for (int i = nums.size() - 1; i >= 0; --i) {
            answer.push_back(cumulativeXor ^ maxVal);  
            cumulativeXor ^= nums[i];  
        }
        
        return answer;    
    }
};