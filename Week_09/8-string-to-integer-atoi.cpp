class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        int i = 0, size = str.length();
        int sign = 1;

        while (str[i] == ' ') i++;

        if (str[i] == '+')
        {
            i++;
        }
        else if (str[i] == '-')
        {
            sign = -1;
            i++;
        }

        for (; i < size; i++)
        {
            if (!isdigit(str[i]))
            {
                break;
            }

            int data = str[i] - '0';
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && data > INT_MAX % 10))
            {
                return INT_MAX;
            }
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && -data < INT_MIN % 10))
            {
                return INT_MIN;
            }
            res = res * 10 + sign * data;
        }

        return res;
    }
};
