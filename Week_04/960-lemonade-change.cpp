class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int m5 = 0, m10 = 0;
        int size = bills.size();

        for (int i = 0; i < size; i++)
        {
            if (bills[i] == 5) m5++;
            else if (bills[i] == 10) m5--, m10++;
            else m5--, m10 > 0 ? m10-- : (m5 -= 2);

            if (m5 < 0) return false;
        }

        return true;
    }
};