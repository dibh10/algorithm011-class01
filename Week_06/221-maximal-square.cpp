class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (row == 0) return 0;

        int col = matrix[0].size();

        vector<vector<int>> dp(row+1, vector<int>(col+1, 0));
        int ans = 0;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == '0') continue;
                dp[i+1][j+1] = min(min(dp[i][j+1], dp[i+1][j]), dp[i][j]) + 1;
                ans = max(ans, dp[i+1][j+1]);
            }
        }

        return ans * ans;
    }
};