class Solution {
public:
    int size = 0;
    int cnt = 0;
    int totalNQueens(int n) {
        if (n <= 0) return 0;

        size = (1 << n) - 1;
        vector<string> squart(n, string(n, '.'));
        solve(squart, n, 0, 0, 0, 0);

        return cnt;
    }
    void solve(vector<string> &squart, int n, int row, int col, int ld, int rd)
    {
        if (row == n)
        {
            cnt++;
            return;
        }

        int bits = size & (~(col | ld | rd));
        while (bits > 0)
        {
            int bit = bits & -bits;
            bits &= bits - 1;

            squart[row][log2(bit)] = 'Q';
            solve(squart, n, row+1, col|bit, (ld|bit)<<1, (rd|bit)>>1);
            squart[row][log2(bit)] = '.';
        }
    }
};