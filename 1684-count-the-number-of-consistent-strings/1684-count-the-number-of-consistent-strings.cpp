class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> s(allowed.begin(), allowed.end());
        int count = 0;
        for (const string& x : words) {
            bool flag = true;
            for (char c : x) {
                if (s.find(c) == s.end()) {
                    flag = false;
                    break;
                }
            }
            if(flag){
                count++;
            }
        }
        return count;
    }
};