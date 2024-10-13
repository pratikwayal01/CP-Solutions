//not my solution but i tried
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
     
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        
        int currentMax = INT_MIN;  
        int rangeStart = 0, rangeEnd = INT_MAX;  
        
       
        for (int i = 0; i < nums.size(); i++) {
            minHeap.push({nums[i][0], {i, 0}});
            currentMax = max(currentMax, nums[i][0]);  
        }
        
       
        while (!minHeap.empty()) {
            auto minElement = minHeap.top();
            minHeap.pop();
            
            int currentMin = minElement.first;
            int listIndex = minElement.second.first;
            int elementIndex = minElement.second.second;
            
          
            if (currentMax - currentMin < rangeEnd - rangeStart) {
                rangeStart = currentMin;
                rangeEnd = currentMax;
            }
            
         
            if (elementIndex + 1 < nums[listIndex].size()) {
                int nextValue = nums[listIndex][elementIndex + 1];
                minHeap.push({nextValue, {listIndex, elementIndex + 1}});
                currentMax = max(currentMax, nextValue);  
            } else {
             
                break;
            }
        }
        
        return {rangeStart, rangeEnd};
    }
    
};