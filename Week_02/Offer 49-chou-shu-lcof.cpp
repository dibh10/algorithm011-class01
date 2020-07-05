class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 0);
        int a = 0, b = 0, c = 0;
        dp[0] = 1;

        for (int i = 1; i < n; i++)
        {
            int n1 = dp[a] * 2, n2 = dp[b] * 3, n3 = dp[c] * 5;
            dp[i] = min(min(n1, n2), n3);
            if (n1 == dp[i]) a++;
            if (n2 == dp[i]) b++;
            if (n3 == dp[i]) c++;
        }

        return dp[n-1];
    }
};
