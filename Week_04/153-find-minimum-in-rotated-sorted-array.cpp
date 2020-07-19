class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin = 0, end = nums.size() - 1, mid = 0;
        if (nums[begin] <= nums[end])
        {
            return nums[0];
        }
        while (begin < end)
        {
            mid = (begin + end) >> 1;
            nums[mid] > nums[end] ? begin = mid + 1 : end = mid;
        }
        return nums[begin];
    }
};