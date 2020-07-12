class Solution {
public:
    vector<vector<int>> res;
    vector<int> item;
    vector<int> used;
    int size;
    vector<vector<int>> permute(vector<int>& nums) {
        size = nums.size();
        used = vector<int>(size, 0);

        generate(0, nums);
        return res;
    }
    void generate(int idx, vector<int>& nums)
    {
        if (item.size() >= size) return;

        for (int i = 0; i < size; i++)
        {
            if (used[i] == 1) continue;

            used[i] = 1;
            item.push_back(nums[i]);
            if (item.size() == size)
            {
                res.push_back(item);
            }
            generate(i+1, nums);
            item.pop_back();
            used[i] = 0;
        }
    }
};
