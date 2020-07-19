class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        int i = 0, maxJump = 0, preMaxJump = 0, jump = 1;

        preMaxJump = maxJump = nums[0];
        for (i = 1; i < nums.size(); i++)
        {
            if (i > maxJump)
            {
                jump++;
                maxJump = preMaxJump;
            }
            preMaxJump = max(preMaxJump, i + nums[i]);
        }

        return jump;
    }
};