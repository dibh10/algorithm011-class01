class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0, size = s.length();
        for (i = 0; i < size; i += 2*k)
        {
            reverse(s.begin() + i, s.begin() + min(size, i + k));
        }
        return s;
    }
};
