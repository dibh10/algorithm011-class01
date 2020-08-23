class Solution {
public:
    int firstUniqChar(string s) {
        int map[127] = {0};

        int i = 0, num = s.length();
        for (i = 0; i < num; i++)
        {
            map[s[i]]++;
        }
        for (i = 0; i < num; i++)
        {
            if (map[s[i]] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};