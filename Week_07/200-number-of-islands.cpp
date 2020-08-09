class Solution {
public:
    vector<vector<bool>> used;
    int row;
    int col;
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        if (row == 0) return 0;

        col = grid[0].size();
        used = vector<vector<bool>>(row, vector<bool>(col, false));

        int i = 0, j = 0, cnt = 0;
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < col; j++)
            {
                if (used[i][j] == false && grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }

        return cnt;
    }
    void dfs(vector<vector<char>>& grid, int r, int c)
    {
        used[r][c] = true;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++)
        {
            int x = c + dx[i];
            int y = r + dy[i];

            if (x < 0 || y < 0 || x >= col || y >= row || used[y][x] || grid[y][x] == '0')
            {
                continue;
            }
            dfs(grid, y, x);
        }
    }
};