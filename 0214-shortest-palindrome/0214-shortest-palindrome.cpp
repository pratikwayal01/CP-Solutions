class Solution {
public:
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        string temp = s + "#" + r;
        vector<int> lps(temp.size(), 0);
        for (int i = 1; i < temp.size(); i++) {
            int j = lps[i - 1];
            while (j > 0 && temp[i] != temp[j]) {
                j = lps[j - 1];
            }
            if (temp[i] == temp[j]) {
                j++;
            }
            lps[i] = j;
        }
        int pre = lps[temp.size() - 1];
        string newS = s.substr(pre);
        reverse(newS.begin(), newS.end());
        return newS + s;
    }
};