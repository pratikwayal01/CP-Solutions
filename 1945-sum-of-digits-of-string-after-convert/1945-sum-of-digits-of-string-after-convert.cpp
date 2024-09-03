class Solution {
public:
    int transform(int t) {
        int res = 0;
        while (t > 0) {
            res += t % 10;
            t /= 10;
        }
        return res;
    }
    int getLucky(string s, int k) {
        int result = 0;
        for (char c : s) {
            int value = c - 'a' + 1;
            while (value > 0) {
                result += value % 10;
                value /= 10;
            }
        }
        while (k > 1) {
            result = transform(result);
            k--;
        }
        return result;
    }
};