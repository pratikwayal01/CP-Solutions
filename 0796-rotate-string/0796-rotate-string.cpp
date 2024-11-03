class Solution {
public:
    bool rotateString(string s, string goal) {
      if (s.size() != goal.size()) {
        return false;
    }
    string double_s = s + s;
    return double_s.find(goal) != string::npos;
    }
};