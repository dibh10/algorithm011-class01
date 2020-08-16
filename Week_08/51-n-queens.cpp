class Solution {
public:
    int size;
    vector<vector<string>> result;
    vector<vector<string>> solveNQueens(int n) {
        if (n <= 0) return result;

        size = (1 << n) - 1;
        vector<string> squarts(n, string(n, '.'));
        solve(squarts, n, 0, 0, 0, 0);

        return result;
    }
    void solve(vector<string> &squart, int n, int row, int col, int ld, int rd)
    {
        if (row == n)
        {
            result.push_back(squart);
            return;
        }

        int bits = size & (~(col | ld | rd));
        while (bits > 0)
        {
            int bit = bits & (-bits);
            bits &= bits - 1;
            squart[row][log2(bit)] = 'Q';
            solve(squart, n, row+1, col|bit, (ld|bit)<<1, (rd|bit)>>1);
            squart[row][log2(bit)] = '.';
        }
    }
};