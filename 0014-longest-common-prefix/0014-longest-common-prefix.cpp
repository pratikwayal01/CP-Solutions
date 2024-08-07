class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string last = strs[strs.size() - 1];
        string str = "";
        for (int i = 0; i < first.length(); i++) {
            if (first[i] != last[i]) {
                return str;
            }
            str += first[i];
        }
        return str;
    }
};