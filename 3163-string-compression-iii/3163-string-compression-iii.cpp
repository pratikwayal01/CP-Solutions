class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        char cnt = '1';
        for (int i = 1; i < word.size(); i++) {
            if ((cnt < '9') && (word[i] == word[i - 1])) {
                cnt++;
            } else {
                ans.push_back(cnt);
                ans += word[i - 1];
                cnt = '1';
            }
        }
        ans.push_back(cnt);
        ans += word.back();
        return ans;
    }
};