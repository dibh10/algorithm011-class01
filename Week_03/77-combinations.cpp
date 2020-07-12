class Solution {
public:
    vector<vector<int>> res;
    vector<int> item;
    vector<vector<int>> combine(int n, int k) {
        generate(1, n, k);
        return res;
    }
    void generate(int idx, int n, int k)
    {
        if (idx > n || item.size() > k) return;

        for (int i = idx; i <= n; i++)
        {
            item.push_back(i);
            if (item.size() == k)
            {
                res.push_back(item);
            }
            generate(i+1, n, k);
            item.pop_back();
        }
    }
};
