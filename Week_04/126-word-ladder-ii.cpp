class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> beginSet{beginWord};
        unordered_map<string, vector<string>> map;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if (wordSet.find(endWord) == wordSet.end()) return res;

        int i = 0, j = 0;
        while (!beginSet.empty() && map.count(endWord) == 0)
        {
            unordered_set<string> delSet{};
            for (auto str : beginSet)
            {
                wordSet.erase(str);
            }
            for (auto str : beginSet)
            {
                for (i = 0; i < str.length(); i++)
                {
                    string tmp = str;
                    for (j = 'a'; j <= 'z'; j++)
                    {
                        if (str[i] == j) continue;

                        tmp[i] = j;
                        if (wordSet.find(tmp) == wordSet.end()) continue;
                        delSet.insert(tmp);
                        map[tmp].push_back(str);
                    }
                }
            }

            beginSet = delSet;
        }

        if (map.count(endWord) == 0) return res;
        dfs(endWord, {}, map);

        return res;
    }

    void dfs(string last, vector<string> path, unordered_map<string, vector<string>>& map)
    {
        path.push_back(last);

        if (map.count(last) == 0)
        {
            reverse(path.begin(), path.end());
            res.push_back(path);
        }
        else
        {
            for (auto str : map[last])
            {
                dfs(str, path, map);
            }
        }
    }
};