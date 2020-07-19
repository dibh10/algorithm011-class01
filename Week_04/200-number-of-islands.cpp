class Solution {
public:
    vector<vector<bool>> used;
    int row = 0;
    int col = 0;
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        if (row == 0) return 0;

        int i = 0, j = 0, cnt = 0;
        col = grid[0].size();
        used = vector<vector<bool>>(row, vector<bool>(col, false));

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
    void dfs(vector<vector<char>>& grid, int y, int x)
    {
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        used[y][x] = true;

        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if (new_x < 0 || new_y < 0 || new_y >= row || new_x >= col || used[new_y][new_x] || grid[new_y][new_x] == '0')
            {
                continue;
            }

            dfs(grid, new_y, new_x);
        }
    }
};

