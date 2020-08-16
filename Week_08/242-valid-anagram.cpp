class Solution {
public:
    bool isAnagram(string s, string t) {
        if (t.length() != s.length()) return false;

        int map[128] = {0};
        int i = 0, size = s.length();
        for (i = 0; i < size; i++)
        {
            map[s[i]]++;
        }

        for (i = 0; i < size; i++)
        {
            if (--map[t[i]] < 0)
                return false;
        }

        return true;
    }
};