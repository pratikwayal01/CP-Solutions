class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int col = n - 2; col >= 0; --col) {
            for (int row = 0; row < m; ++row) {
                if (row > 0 && grid[row - 1][col + 1] > grid[row][col]) {
                    dp[row][col] = max(dp[row][col], 1 + dp[row - 1][col + 1]);
                }
                if (grid[row][col + 1] > grid[row][col]) {
                    dp[row][col] = max(dp[row][col], 1 + dp[row][col + 1]);
                }
                if (row < m - 1 && grid[row + 1][col + 1] > grid[row][col]) {
                    dp[row][col] = max(dp[row][col], 1 + dp[row + 1][col + 1]);
                }
            }
        }

        int maxMovesCount = 0;
        for (int row = 0; row < m; ++row) {
            maxMovesCount = max(maxMovesCount, dp[row][0]);
        }
        return maxMovesCount; 
    }
};