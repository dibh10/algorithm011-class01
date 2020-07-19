class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0, end = nums.size()-1;
        int mid = 0;
        while (begin <= end)
        {
            mid = (begin + end) >> 1;
            if (target == nums[mid])
            {
                return mid;
            }
            
            if (nums[mid] >= nums[begin])
            {
                if (target >= nums[begin] && target < nums[mid])
                {
                    end = mid - 1;
                }
                else
                {
                    begin = mid + 1;
                }
            }
            else
            {
                if (target > nums[mid] && target <= nums[end])
                {
                    begin = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};