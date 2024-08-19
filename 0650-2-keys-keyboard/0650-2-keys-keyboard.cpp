class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        int factor = 2;

        while (n > 1) {
            while (n % factor == 0) {
                ans += factor;
                n /= factor;
            }
            factor++;
        }

        return ans;
    }
};