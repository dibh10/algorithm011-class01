class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;

        if (strs.empty()) return res;

        unordered_map<string, int> map;
        int i = 0, size = strs.size(), idx = 0;

        for (i = 0; i < size; i++)
        {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());

            if (map.count(tmp) == 0)
            {
                map[tmp] = idx++;
                res.push_back(vector<string>{strs[i]});
            }
            else
                res[map[tmp]].push_back(strs[i]);
        }

        return res;
    }
};