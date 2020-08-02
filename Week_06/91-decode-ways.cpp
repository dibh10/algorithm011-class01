class Solution {
public:
    int numDecodings(string s) {
        int size = s.length();
        if (s[0] == '0') return 0;

        int i = 0;
        vector<int> dp(size + 1, 0);

        dp[0] = 1;
        dp[1] = 1;
        for (i = 2; i <= size; i++)
        {
            string str = s.substr(i - 2, 2);
            int one = 0;
            s[i-1] == '0' ? one = 0 : one = dp[i-1];
            if (str >= "10" && str <= "26")
            {
                dp[i] = one + dp[i-2];
            }
            else
            {
                dp[i] = one;
            }
        }

        return dp[size];
    }
};
