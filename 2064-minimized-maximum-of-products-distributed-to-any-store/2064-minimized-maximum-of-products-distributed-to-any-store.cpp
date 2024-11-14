class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1,
            right = *max_element(quantities.begin(), quantities.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canDistribute(n, quantities, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool canDistribute(int n, vector<int>& quantities, int k) {
        int stores = 0;
        for (int q : quantities) {
            stores += (q + k - 1) / k;
        }
        return stores <= n;
    }
};