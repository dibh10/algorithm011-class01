class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1, i = 0, data = 0;
        vector<int> nums;

        if (digits.empty()) return nums;

        for (i = digits.size() - 1; i >= 0; i--)
        {
            data = digits[i] + carry;
            if (data >= 10)
            {
                carry = 1;
                data -= 10;
            }
            else
            {
                carry = 0;
            }
            nums.push_back(data);
        }
        if (carry != 0)
            nums.push_back(1);

        reverse(nums.begin(), nums.end());

        return nums;
    }
};