class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0, k = 0, size = s.length();

        for (i = 0; i < size; i++)
        {
            j = i;
            while (j < size && s[j] != ' ') j++;
            k = j-1;
            while (i < k) swap(s[i++], s[k--]);
            i = j;
        }

        return s;
    }
};
