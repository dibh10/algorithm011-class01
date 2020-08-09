class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> setword(wordList.begin(), wordList.end());

        if (setword.count(endWord) == 0) return 0;

        unordered_set<string> setbegin{beginWord};
        unordered_set<string> setend{endWord};

        int cnt = 1;
        while (!setbegin.empty())
        {
            unordered_set<string> delset;

            for (auto word : setbegin)
            {
                setword.erase(word);
            }
            cnt++;

            for (string word : setbegin)
            {
                for (int j = 0; j < word.length(); j++)
                {
                    string tmp = word;
                    for (int i = 'a'; i <= 'z'; i++)
                    {
                        tmp[j] = i;

                        if (setword.count(tmp) == 0) continue;
                        if (setend.count(tmp) != 0) return cnt;

                        delset.insert(tmp);
                    }
                }
            }

            setbegin = delset;
            if (setbegin.size() > setend.size())
            {
                swap(setbegin, setend);
            }
        }

        return 0;
    }
};