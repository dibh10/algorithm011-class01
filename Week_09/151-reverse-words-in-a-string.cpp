class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0, size = s.length();
        string res;

        for (i = 0; i < size; i++)
        {
            if (s[i] == ' ') continue;

            j = i;
            while (j < size && s[j] != ' ')
            {
                j++;
            }

            if (res != "")
            {
                res = s.substr(i, j - i) + ' ' + res;
            }
            else
            {
                res = s.substr(i, j - i);
            }

            i = j;
        }

        return res;
    }
};