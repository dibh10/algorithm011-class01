class Solution {
public:
    string reverseOnlyLetters(string S) {
        int i = 0, size = S.length(), j = size - 1;

        while (i < j)
        {
            while (i < j && !isalpha(S[i])) i++;
            while (i < j && !isalpha(S[j])) j--;
            if (i < j) swap(S[i++], S[j--]);
        }

        return S;
    }
};
