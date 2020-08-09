class Solution {
public:
    vector<vector<string>> res;
    vector<string> squart;
    vector<vector<string>> solveNQueens(int n) {

        squart = vector<string>(n, string(n, '.'));
        generate(0, n);

        return res;
    }
    void generate(int row,  int n)
    {
        if (row >= n)
        {
            res.push_back(squart);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (!isVaild(row, i, n)) continue;

            squart[row][i] = 'Q';
            generate(row+1, n);
            squart[row][i] = '.';
        }
    }
    bool isVaild(int row, int col, int n)
    {
        int i = 0, j = 0;

        for (i = 0; i < row; i++)
        {
            if (squart[i][col] == 'Q')
            {
                return false;
            }
        }
        for (i = row-1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (squart[i][j] == 'Q')
            {
                return false;
            }
        }
        for (i = row-1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (squart[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }
};