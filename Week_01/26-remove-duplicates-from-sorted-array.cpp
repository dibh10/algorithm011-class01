class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int i = 0, idx = 1;

        if (len == 0) return 0;
        
        for (i = 1; i < len; i++)
        {
            if (nums[i] == nums[i-1]) continue;
            nums[idx++] = nums[i];
        }

        return idx;
    }
};