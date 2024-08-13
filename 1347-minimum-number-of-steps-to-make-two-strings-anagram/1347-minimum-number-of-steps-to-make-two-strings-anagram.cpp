class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> arr(26, 0);

        for (char c : s) {
            arr[c - 'a']++;
        }

        for (char c : t) {
            arr[c - 'a']--;
        }

        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (arr[i] > 0) {
                count += arr[i];
            }
        }

        return count;
    }
};