class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;

        if (nums.empty()) return {};

        for (int i = 0; i < nums.size(); i++)
        {
            if (map.count(nums[i]) == 0)
            {
                map[target - nums[i]] = i;
            }
            else
            {
                return vector<int> {map[nums[i]], i};
            }
        }

        return {};
    }
};
