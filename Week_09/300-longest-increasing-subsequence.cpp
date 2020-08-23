class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int i = 0, size = nums.size();
        vector<int> stack;

        if (nums.empty()) return 0;
        stack.push_back(nums[0]);

        for (i = 1; i < size; i++)
        {
            if (nums[i] > stack.back())
            {
                stack.push_back(nums[i]);
            }
            else
            {
                int idx = lower_bound(stack.begin(), stack.end(), nums[i]) - stack.begin();
                stack[idx] = nums[i];
            }        
        }

        return stack.size();
    }
};