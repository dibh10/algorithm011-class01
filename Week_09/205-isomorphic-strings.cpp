class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char map[127] = {0};
        char map_t[127] = {0};
        int i = 0, size = s.length();

        for (i = 0; i < size; i++)
        {
            if (map[s[i]] == 0)
            {
                if (map_t[t[i]] != 0)
                {
                    return false;
                }
                map[s[i]] = t[i];
                map_t[t[i]] = s[i];
            }
            else
            {
                if (map[s[i]] != t[i])
                {
                    return false;
                }
            }
        }

        return true;
    }
};
