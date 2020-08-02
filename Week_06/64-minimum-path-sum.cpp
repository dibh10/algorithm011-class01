class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        if (row == 0) return 0;

        int col = grid[0].size(), i = 0, j = 0;
        if (col == 0) return 0;

        vector<vector<int>> dp(row, vector<int>(col, 0));

        dp[0][0] = grid[0][0];
        for (i = 1; i < col; i++)
        {
            dp[0][i] = grid[0][i] + dp[0][i-1];
        }
        for (i = 1; i < row; i++)
        {
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }

        for (i = 1; i < row; i++)
        {
            for (j = 1; j < col; j++)
            {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }

        return dp[row-1][col-1];
    }
};
