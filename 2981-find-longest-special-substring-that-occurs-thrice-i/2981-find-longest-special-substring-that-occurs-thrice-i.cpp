class Solution {
public:
    int maximumLength(string s) {
    int n = s.length();
    int maxLength = -1;

    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            string sub = s.substr(i, j - i);

       
            char firstChar = sub[0];
            bool isSpecial = true;
            for (char c : sub) {
                if (c != firstChar) {
                    isSpecial = false;
                    break;
                }
            }

            if (!isSpecial) continue;

         
            int count = 0;
            for (int k = 0; k <= n - sub.length(); ++k) {
                if (s.substr(k, sub.length()) == sub) {
                    ++count;
                }
            }


            if (count >= 3) {
                maxLength = max(maxLength, (int)sub.length());
            }
        }
    }

    return maxLength;
    }
};