class Solution {
public:
    vector<bool> used;
    int row = 0;
    int col = 0;
    void solve(vector<vector<char>>& board) {
        row = board.size();
        if (row == 0) return;

        col = board[0].size();
        int i = 0, j = 0;
        for (i = 0; i < col; i++)
        {
            dfs(board, 0, i);
            dfs(board, row-1, i);
        }
        for (j = 1; j < row-1; j++)
        {
            dfs(board, j, 0);
            dfs(board, j, col-1);
        }

        for (i = 0; i < row; i++)
        {
            for (j = 0; j < col; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
    void dfs(vector<vector<char>>& board, int r, int c) {
        if (r < 0 || c < 0 || r >= row || c >= col || board[r][c] == 'X' || board[r][c] == '#')
        {
            return;
        }

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        board[r][c] = '#';

        for (int i = 0; i < 4; i++)
        {
            int x = c + dx[i];
            int y = r + dy[i];
            dfs(board, y, x);
        }
    }
};
