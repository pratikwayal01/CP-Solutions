class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0;
        int read = 0;
        while (read < chars.size()) {
            char currentChar = chars[read];
            int count = 0;

            while (read < chars.size() && chars[read] == currentChar) {
                read++;
                count++;
            }
            chars[write++] = currentChar;

            if (count > 1) {
                for (char digit : to_string(count)) {
                    chars[write++] = digit;
                }
            }
        }

        return write; 
    }
};