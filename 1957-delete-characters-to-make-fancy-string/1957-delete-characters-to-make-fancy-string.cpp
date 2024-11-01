class Solution {
public:
    string makeFancyString(string str) {
        string result;
        int count = 1;

        for (size_t i = 0; i < str.size(); ++i) {
            if (i > 0 && str[i] == str[i - 1]) {
                count++;
            } else {
                count = 1;
            }
            if (count < 3) {
                result += str[i];
            }
        }

        return result;
    }
};