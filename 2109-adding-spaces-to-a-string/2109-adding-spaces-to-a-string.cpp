class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result = "";
        int j = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            while (j < spaces.size() && spaces[j] == i) {
                result += " ";
                j++;
            }

            result += s[i];
        }

        return result;
    }
};