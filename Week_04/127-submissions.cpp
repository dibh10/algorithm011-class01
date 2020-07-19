class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordset(wordList.begin(), wordList.end());
        unordered_set<string> beginset{beginWord};
        unordered_set<string> endset{endWord};

        if (wordset.count(endWord) == 0) return 0;

        int i = 0, j = 0, cnt = 1;

        while (!beginset.empty())
        {
            unordered_set<string> delset;

            for (auto &word : beginset)
            {
                wordset.erase(word);
            }
            cnt++;

            for (auto &word : beginset)
            {
                for (j = 0; j < word.length(); j++)
                {
                    string tmp = word;
                    for (i = 'a'; i <= 'z'; i++)
                    {
                        tmp[j] = i;

                        if (wordset.count(tmp) == 0) continue;
                        if (endset.count(tmp) != 0) return cnt;
                        delset.insert(tmp);
                    }
                }
            }

            beginset = delset;
            if (beginset.size() > endset.size())
                swap(beginset, endset);
        }

        return 0;
    }
};
