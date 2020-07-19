class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, size = prices.size(), sum = 0, diff = 0;

        for (i = 1; i < size; i++)
        {
            diff = prices[i] - prices[i-1];
            if (diff > 0)
            {
                sum += diff;
            }
        }

        return sum;
    }
};
