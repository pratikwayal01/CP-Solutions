class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> count(3, 0);
        int n = s.length();
        

        for(char c : s) {
            count[c - 'a']++;
        }
        
        if(count[0] < k || count[1] < k || count[2] < k) {
            return -1;
        }
        
        vector<int> target(3);
        for(int i = 0; i < 3; i++) {
            target[i] = count[i] - k;
        }
        
        vector<int> window(3, 0);
        int left = 0, maxLen = 0;
        
        for(int right = 0; right < n; right++) {
            window[s[right] - 'a']++;
            
            while(left <= right && 
                  (window[0] > target[0] || 
                   window[1] > target[1] || 
                   window[2] > target[2])) {
                window[s[left] - 'a']--;
                left++;
            }
            
            maxLen = max(maxLen, right - left + 1);
        }
        
        return n - maxLen;
    }
};