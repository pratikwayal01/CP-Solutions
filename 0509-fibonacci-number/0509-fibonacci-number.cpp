class Solution {
public:
    int fib(int n) {
        int pre1 = 0;
        int pre2 = 1;
        for (int i = 1; i <= n; i++) {
            int cur = pre1 + pre2;
            pre2 = pre1;
            pre1 = cur;
        }
        return pre1;
    }
};