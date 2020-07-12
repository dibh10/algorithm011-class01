class Solution {
public:
    unordered_map<int, int> map;
    int majorityElement(vector<int>& nums) {
        int size = nums.size();

        for (auto data : nums)
        {
            map[data]++;
        }
        for (auto it : map)
        {
            if (it.second > (nums.size() >> 1))
                return it.first;
        }

        return 0;
    }
};