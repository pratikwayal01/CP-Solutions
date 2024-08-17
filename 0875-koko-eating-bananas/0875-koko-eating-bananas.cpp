class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while (low < high) {
            int mid = (low + high) / 2;
            int hours = 0;
            for (int pile : piles) {
                hours += (pile + mid - 1) / mid; 
            }
            if (hours <= h) {
                high = mid; 
            } else {
                low = mid + 1;  
            }
        }
        return low;
    }
};