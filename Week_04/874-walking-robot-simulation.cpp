class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int size = commands.size(), i = 0;
        int curx = 0, cury = 0, curdir = 0;
        int dirx[4] = {0, 1, 0, -1};
        int diry[4] = {1, 0, -1, 0};
        int res = 0;
        set<pair<int, int>> set;

        for (auto &v : obstacles)
        {
            set.insert(make_pair(v[0], v[1]));
        }

        for (i = 0; i < size; i++)
        {
            if (commands[i] == -1) curdir = (curdir + 1) & 3;
            else if (commands[i] == -2) curdir = (curdir + 3) & 3;
            else
            {
                for (int j = 0; j < commands[i]; j++)
                {
                    int tmpx = curx + dirx[curdir];
                    int tmpy = cury + diry[curdir];

                    if (set.count(make_pair(tmpx, tmpy)) == 0)
                    {
                        curx = tmpx;
                        cury = tmpy;
                        res = max(res, curx * curx + cury * cury);
                    }
                    else
                    {
                        break;//无法继续往下走了，直接退出本次命令即可
                    }
                }

            }
        }

        return res;
    }
};
