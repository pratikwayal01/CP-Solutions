class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return backtrack(s, 0, seen);
    }

private:
    int backtrack(const string& s, int start, unordered_set<string>& seen) {
        if (start == s.length()) {
            return 0;
        }
        int maxSplits = 0;
        string current = "";
        for (int i = start; i < s.length(); ++i) {
            current += s[i]; 
            if (seen.find(current) == seen.end()) {
                seen.insert(current); 
                maxSplits = max(maxSplits, 1 + backtrack(s, i + 1,seen)); 
                seen.erase(current); 
            }
        }

        return maxSplits; 
    }
};