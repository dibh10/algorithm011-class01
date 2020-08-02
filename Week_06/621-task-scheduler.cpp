class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int size = tasks.size();
        if (size == 0) return 0;

        vector<int> map(26, 0);
        for (auto c : tasks)
        {
            map[c-'A']++;
        }

        sort(map.rbegin(), map.rend());

        int num = (map[0] - 1) * (n + 1) + 1;
        for (int i = 1; i < 26 && map[i] > 0; i++)
        {
            if (map[0] == map[i]) num++;
        }

        return size > num ? size : num;
    }
};
