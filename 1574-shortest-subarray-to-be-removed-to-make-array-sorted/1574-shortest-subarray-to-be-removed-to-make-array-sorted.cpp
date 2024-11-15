class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        int j = n - 1;
        while (i < n - 1 && arr[i] <= arr[i + 1]) {
            i++;
        }
        if (i == n - 1) {
            return 0;
        }
        while (j > 0 && arr[j] >= arr[j - 1]) {
            j--;
        }
        int ans = min(n - i - 1, j);
        int x = 0, y = j;
        while (x <= i && y < n) {
            if (arr[x] <= arr[y]) {
                ans = min(ans, y - x - 1);
                x++;
            } else {
                y++;
            }
        }
        return ans;
    }
};